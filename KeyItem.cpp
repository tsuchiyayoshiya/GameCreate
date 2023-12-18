#include "KeyItem.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"

#include "Engine/BoxCollition"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"


//�R���X�g���N�^
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1)
{
}

//������
void KeyItem::Initialize()
{

    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void KeyItem::Update()
{
    bool yPosition = false;
    
    transform_.position_.y += 0.01f;
    if (transform_.position_.y == 1)
    {
        yPosition = true;
    }
    else if (yPosition = true)
    {
        transform_.position_.y -= 0.01f;
    }
}

//�`��
void KeyItem::Draw()
{
    transform_.position_ = { 5,3,5 };

    transform_.rotate_.y = 180;

    transform_.scale_ = { 0.2,0.2,0.2 };

    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void KeyItem::Release()
{
}
