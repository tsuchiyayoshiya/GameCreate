#include "Player.h"
#include "KeyItem.h"

#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

#define CAM_TYPE_FIXED 0 //固定
#define CAM_TYPE_TPS_NO_ROT 1 //三人称（回転無し）
#define CAM_TYPE_TPS 2        //三人称
#define CAM_TYPE_FPS 3        //一人称
#define CAM_TYPE_MAX 4 

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), pStage(nullptr), pText(nullptr),ItemKill(false),ItemCount_(0), camType_(1)
{
	pStage = (Stage*)FindObject("Stage");
}

//初期化
void Player::Initialize()
{
	//鍵の所得情報
	pText = new Text;
	pText->Initialize();


	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.2, 0), 0.5f);
	AddCollider(collision);
	//モデルデータのロード
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 7.5,0.5,3 };
}

//更新
void Player::Update()
{
	prevPosition_ = transform_.position_;

	XMFLOAT3 FMove = XMFLOAT3(0, 0, 0);

	if (Input::IsKey(DIK_W))
	{
		FMove.z += 0.1f;
		transform_.position_.z += 0.1f;

	}
	if (Input::IsKey(DIK_S))
	{
		FMove.z += -0.1f;
		transform_.position_.z -= 0.1f;

	}
	if (Input::IsKey(DIK_A))
	{
		FMove.x = -0.1f;
		transform_.position_.x -= 0.1f;

	}
	if (Input::IsKey(DIK_D))
	{
		FMove.x = 0.1f;
		transform_.position_.x += 0.1f;

	}


	//FMove.x = Input::GetPadStickL(0).x;
	//FMove.z = Input::GetPadStickL(0).y;


	XMVECTOR vMove;
	vMove = XMLoadFloat3(&FMove);
	vMove = XMVector3Normalize(vMove);
	vMove *= 0.1f;
	XMStoreFloat3(&FMove, vMove);

	transform_.position_.x += FMove.x;
	transform_.position_.z += FMove.z;

	//向き変更
	XMVECTOR vLength = XMVector3Length(vMove);
	float length = XMVectorGetX(vLength);
	
	//if (length != 0)
	{
		XMVECTOR vFront = { 0,0,1,0 };//正規化
		vMove = XMVector3Normalize(vMove);

		XMVECTOR vDot = XMVector3Dot(vFront, vMove);
		float dot = XMVectorGetX(vDot);
		float angle = acos(dot);

		// XMVector3Cross : vFront と vMove の外積求める
		XMVECTOR vCross = XMVector3Cross(vFront, vMove);

		// vFront と vMove の外積が下向きだったら angle に-1をかけて、向きを反対にする
		if (XMVectorGetY(vCross) < 0)
		{
			angle *= -1;
		}

		transform_.rotate_.y = XMConvertToDegrees(angle);
	}
	
	//壁の判定
	int checkX1;
	int checkX2;
	int checkZ1;
	int checkZ2;

	//右
	{
		checkX1 = (int)(transform_.position_.x + 0.3f);
		checkZ1 = (int)(transform_.position_.z + 0.2f);
		checkX2 = (int)(transform_.position_.x + 0.3f);
		checkZ2 = (int)(transform_.position_.z - 0.2f);

		if (pStage->IsWall(checkX1, checkZ1) == true ||
			pStage->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.x = (float)((int)transform_.position_.x) + 0.7f;
		}
	}
	//左
	{
		checkX1 = (int)(transform_.position_.x - 0.3f);
		checkZ1 = (int)(transform_.position_.z + 0.2f);
		checkX2 = (int)(transform_.position_.x - 0.3f);
		checkZ2 = (int)(transform_.position_.z - 0.2f);

		if (pStage->IsWall(checkX1, checkZ1) == true ||
			pStage->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.x = (float)((int)transform_.position_.x) + 0.3f;
		}
	}
	//奥
	{
		checkX1 = (int)(transform_.position_.x + 0.2f);
		checkZ1 = (int)(transform_.position_.z + 0.3f);
		checkX2 = (int)(transform_.position_.x - 0.2f);
		checkZ2 = (int)(transform_.position_.z + 0.3f);

		if (pStage->IsWall(checkX1, checkZ1) == true ||
			pStage->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.z = (float)((int)transform_.position_.z) + 0.7f;
		}
	}
	//手前

	checkX1 = (int)(transform_.position_.x + 0.2f);
	checkZ1 = (int)(transform_.position_.z - 0.3f);
	checkX2 = (int)(transform_.position_.x - 0.2f);
	checkZ2 = (int)(transform_.position_.z - 0.3f);

	if (pStage->IsWall(checkX1, checkZ1) == true ||
		pStage->IsWall(checkX2, checkZ2) == true)
	{
		transform_.position_.z = (float)((int)transform_.position_.z) + 0.3f;
	}


	if (Input::IsKeyDown(DIK_E))
	{
		camType_ += 1;
		if (camType_ == CAM_TYPE_MAX)
		{
			camType_ = CAM_TYPE_FIXED;
		}
	}

	//プレイヤーの現在値をベクトル型に変換
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	//フレーム移動ベクトル
	XMVECTOR fMove = { 0.0f, 0.0f, 0.1f, 0.0f };
	//transform_.rotate_.y度回転させる行列を作成
	XMMATRIX mRotY;
	mRotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//移動ベクトルを変形（戦車と同じ向きに回転）させる
	fMove = XMVector3TransformCoord(fMove, mRotY);

	XMVECTOR vCam;
	XMFLOAT3 camTag = transform_.position_;
	XMFLOAT3 camPos = transform_.position_;

	switch (camType_)
	{
	case CAM_TYPE_FIXED:
		Camera::SetPosition(XMFLOAT3(0, 50, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	case CAM_TYPE_TPS_NO_ROT:
		Camera::SetTarget(transform_.position_);
		XMFLOAT3 camPos = transform_.position_;
		camPos.y += 7;
		camPos.z -= 5;
		Camera::SetPosition(camPos);
		break;
	case CAM_TYPE_TPS:
		Camera::SetTarget(transform_.position_);
		vCam = { 0, 5, -5, 0 };
		vCam = XMVector3TransformCoord(vCam, mRotY);
		//XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, vPos + vCam);
		Camera::SetPosition(camPos);
		break;
	case CAM_TYPE_FPS:
		vCam = { 0,0,0,0 };
		XMStoreFloat3(&camTag, vPos + fMove);
		Camera::SetTarget(camTag);
		vCam = XMVector3TransformCoord(vCam, mRotY);
		XMStoreFloat3(&camPos, vPos + vCam);
		Camera::SetPosition(camPos);
		break;
	}
	
	

}


void Player::OnCollision(GameObject* pTarget)
{
	GameObject* pGameObject = FindObject("KeyItem");
	if (pTarget->GetObjectName() == "KeyItem")
	{
		ItemCount_++;
	}
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

