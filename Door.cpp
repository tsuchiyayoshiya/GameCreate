#include "Door.h"
#include "Player.h"

#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Door::Door(GameObject* parent)
    : GameObject(parent, "Door"), hModel_(-1),hPict_(-1),Open_(false)
{
}

//������
void Door::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 49, 0, 49};
    hModel_ = Model::Load("door.fbx");
    assert(hModel_ >= 0);
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("OpenDoor.png");
    assert(hPict_ >= 0);
}

//�X�V
void Door::Update()
{
    float timer;
    timer += 1.0f;

    while (timer == 1800)
    {

    }
    //�������ׂď����������̏���
    Player* pPlayer = (Player*)FindObject("Player");
    if (pPlayer->getItemCount() == 11)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
        AddCollider(collision);
        Open_ = true;
    }
}

//�`��
void Door::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    if (Open_ == true)
    {
        //�摜�f�[�^�̃��[�h
        hPict_ = Image::Load("OpenDoor.png");
        assert(hPict_ >= 0);
    }
}

void Door::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_NEXT);
    }
}

//�J��
void Door::Release()
{
}
