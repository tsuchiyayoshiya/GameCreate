#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include"KeyItem.h"
#include"Door.h"
#include"Enemy.h"

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
    Instantiate<Stage>(this);
    Instantiate<Player>(this);
   // Instantiate<KeyCsv>(this);
    for (int i = 0; i < 6; i++){
    Instantiate<KeyItem>(this);
    }
    Instantiate<Door>(this);
    for(int i = 0;i<6;i++)
   Instantiate<Enemy>(this);  
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
