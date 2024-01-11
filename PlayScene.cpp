#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include"KeyItem.h"
#include"Door.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"



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
    for(int i = 0;i<6;i++){
    Instantiate<KeyItem>(this);
    }
    Instantiate<Door>(this);
    // �������ׂĎ��I������Ƃ��̏���
   // if (FindObject("KeyItem") == nullptr)
   // {
    //    SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");//�N���A�V�[����\������
    //    pSceneManager->ChangeScene(SCENE_ID_CLEAR);
   // }
    
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
