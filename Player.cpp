#include "Player.h"
#include "KeyItem.h"

#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

#define CAM_TYPE_FIXED 0 //�Œ�
#define CAM_TYPE_TPS_NO_ROT 1 //�O�l�́i��]�����j
#define CAM_TYPE_TPS 2        //�O�l��
#define CAM_TYPE_FPS 3        //��l��
#define CAM_TYPE_MAX 4 

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), pStage(nullptr), pText(nullptr),ItemKill(false),ItemCount_(0), camType_(1)
{
	pStage = (Stage*)FindObject("Stage");
}

//������
void Player::Initialize()
{
	//���̏������
	pText = new Text;
	pText->Initialize();


	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.2, 0), 0.5f);
	AddCollider(collision);
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 7.5,0.5,3 };
}

//�X�V
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

	//�����ύX
	XMVECTOR vLength = XMVector3Length(vMove);
	float length = XMVectorGetX(vLength);
	
	//if (length != 0)
	{
		XMVECTOR vFront = { 0,0,1,0 };//���K��
		vMove = XMVector3Normalize(vMove);

		XMVECTOR vDot = XMVector3Dot(vFront, vMove);
		float dot = XMVectorGetX(vDot);
		float angle = acos(dot);

		// XMVector3Cross : vFront �� vMove �̊O�ϋ��߂�
		XMVECTOR vCross = XMVector3Cross(vFront, vMove);

		// vFront �� vMove �̊O�ς��������������� angle ��-1�������āA�����𔽑΂ɂ���
		if (XMVectorGetY(vCross) < 0)
		{
			angle *= -1;
		}

		transform_.rotate_.y = XMConvertToDegrees(angle);
	}
	
	//�ǂ̔���
	int checkX1;
	int checkX2;
	int checkZ1;
	int checkZ2;

	//�E
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
	//��
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
	//��
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
	//��O

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

	//�v���C���[�̌��ݒl���x�N�g���^�ɕϊ�
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	//�t���[���ړ��x�N�g��
	XMVECTOR fMove = { 0.0f, 0.0f, 0.1f, 0.0f };
	//transform_.rotate_.y�x��]������s����쐬
	XMMATRIX mRotY;
	mRotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//�ړ��x�N�g����ό`�i��ԂƓ��������ɉ�]�j������
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

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

