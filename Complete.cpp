#include "Complete.h"
#include "BackGround.h"
#include "Player.h"
#include "Stage.h"
#include "KeyItem.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"


//�R���X�g���N�^
Complete::Complete(GameObject* parent)
    : GameObject(parent, "Complete"), hModel_(-1)
{
}

//������
void Complete::Initialize()
{
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Complete::Update()
{
}

//�`��
void Complete::Draw()
{
    //�ʒu���]��傫��
    transform_.position_ = { 5,1,5 };
    transform_.rotate_.y = 180;
    transform_.scale_ = { 2,2,2 };

    //-------------------------------------//
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Complete::Release()
{
}
/*
//�����ɓ�������
void Complete::OnCollision(GameObject* pTarget)
{
    bool ItemKill = false;
    //�v���C���[��������ɗ�����
    if (pTarget->GetObjectName() == "Player")
    {
        //���������Ƃ��̏���
        //pTarget->KillMe();//���������e������
        this->KillMe();//����������
        ItemKill = true;
    }
    if (ItemKill == true)
    {
        Instantiate<Complete>(this);
    }
}
*/