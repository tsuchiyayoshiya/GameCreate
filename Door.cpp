#include "Door.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Door::Door(GameObject* parent)
    : GameObject(parent, "Door"), hModel_(-1)
{
}

//������
void Door::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 10,4.5,5};
    hModel_ = Model::Load("door.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Door::Update()
{
}

//�`��
void Door::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Door::Release()
{
}
