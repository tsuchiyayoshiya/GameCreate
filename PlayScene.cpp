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



//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"),hModel_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
    //カメラの位置
    Camera::SetPosition(XMFLOAT3(7.5, 10, -5));
    Camera::SetTarget(XMFLOAT3(7.5, 2, 3));
    Instantiate<Stage>(this);
    Instantiate<Player>(this);
    for (int i = 0; i < 6; i++){
    Instantiate<KeyItem>(this);
    }
    Instantiate<Door>(this);
    Instantiate<Enemy>(this);  
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
    
}

//開放
void PlayScene::Release()
{
}
