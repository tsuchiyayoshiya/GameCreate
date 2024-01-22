#include "Door.h"
#include "Player.h"

#include "Engine/BoxCollider.h"
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
    transform_.position_ = { 10, 0, 10 };
    hModel_ = Model::Load("door.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Door::Update()
{
    //�������ׂď����������̏���
    Player* pPlayer = (Player*)FindObject("Player");
    if (pPlayer->getItemCount() == 11)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
        AddCollider(collision);
    }
}

//�`��
void Door::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
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
