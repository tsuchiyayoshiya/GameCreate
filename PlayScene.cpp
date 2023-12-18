#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include"KeyItem.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"


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
    Instantiate<KeyItem>(this);
   // void KeyItem::OnCollision(GameObject * pTarget);
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
