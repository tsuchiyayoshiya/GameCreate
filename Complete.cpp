#include "Complete.h"
#include "BackGround.h"
#include "Player.h"
#include "Stage.h"
#include "KeyItem.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"


//コンストラクタ
Complete::Complete(GameObject* parent)
    : GameObject(parent, "Complete"), hModel_(-1)
{
}

//初期化
void Complete::Initialize()
{
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);
}

//更新
void Complete::Update()
{
}

//描画
void Complete::Draw()
{
    //位置や回転や大きさ
    transform_.position_ = { 5,1,5 };
    transform_.rotate_.y = 180;
    transform_.scale_ = { 2,2,2 };

    //-------------------------------------//
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Complete::Release()
{
}
/*
//何かに当たった
void Complete::OnCollision(GameObject* pTarget)
{
    bool ItemKill = false;
    //プレイヤーがあたりに来た時
    if (pTarget->GetObjectName() == "Player")
    {
        //当たったときの処理
        //pTarget->KillMe();//当たった弾を消す
        this->KillMe();//自分を消す
        ItemKill = true;
    }
    if (ItemKill == true)
    {
        Instantiate<Complete>(this);
    }
}
*/