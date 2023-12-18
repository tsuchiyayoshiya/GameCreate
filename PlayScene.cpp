#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include"KeyItem.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"


//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"),hModel_(-1)
{
}

//������
void PlayScene::Initialize()
{
    //�J�����̈ʒu
    Camera::SetPosition(XMFLOAT3(7.5, 10, -5));
    Camera::SetTarget(XMFLOAT3(7.5, 2, 3));
    Instantiate<Stage>(this);
    Instantiate<Player>(this);
    Instantiate<KeyItem>(this);
   // void KeyItem::OnCollision(GameObject * pTarget);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
    
}

//�J��
void PlayScene::Release()
{
}
