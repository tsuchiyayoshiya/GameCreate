#include "PlayScene.h"
#include"BackGround.h"
#include"Player.h"
#include "Engine/Image.h"


//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), hPict_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<BackGround>(this);
    Instantiate<Player>(this);
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
