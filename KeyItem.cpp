#include "KeyItem.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include "Complete.h"
#include <cstdlib> // rand()�֐����g�p���邽�߂̃w�b�_�[
#include <ctime>   // time()�֐����g�p���邽�߂̃w�b�_�[

#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"


//�R���X�g���N�^
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1), ItemKill(false)
{
}

//������
void KeyItem::Initialize()
{
    // ���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);

    // �����ʒu�̃����_���ݒ�
    transform_.position_ = { (float)(rand() % 45 + 1), 1, (float)(rand() % 45 + 1) };

    // ��]�ƃX�P�[���̐ݒ�
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2, 0.2, 0.2 };

    // 20�̊Ԋu�ō��W�𒲐�
    AdjustPositionWithGap(15.0f);

    // �Փ˔���p�̃{�b�N�X�R���C�_�[�̍쐬�ƒǉ�
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);
}

// 20�̊Ԋu�ō��W�𒲐�����֐�
void KeyItem::AdjustPositionWithGap(float gap)
{
    int gapCountX = static_cast<int>(transform_.position_.x / gap);
    int gapCountZ = static_cast<int>(transform_.position_.z / gap);

    transform_.position_.x = gapCountX * gap + gap / 2.0f;
    transform_.position_.z = gapCountZ * gap + gap / 2.0f;
}

//�X�V
void KeyItem::Update()
{
    
}

//�`��
void KeyItem::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}   

//�J��
void KeyItem::Release()
{
}

void KeyItem::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        //���������Ƃ��̏���
        //pTarget->KillMe();//���������e������
        this->KillMe();//����������
    }
}
