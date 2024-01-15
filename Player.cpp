#include "Player.h"
#include "KeyItem.h"

#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"


//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), pStage(nullptr), pText(nullptr),ItemKill(false)
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

	transform_.position_.x = 7.5;
	transform_.position_.z = 3;

	//transform_.rotate_.y = 5.0f;
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

	
	
}

/*
void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "KeyItem")
	{
		//���������Ƃ��̏���
		pTarget->KillMe();//���������e������
		//this->KillMe();//����������

		Instantiate<KeyItem>(this);
		//ItemKill = true;
	}
	/*
	if (ItemKill == true)
	{

	}

}
*/
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

