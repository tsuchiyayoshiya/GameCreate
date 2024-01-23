#include "KeyItem.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include "Complete.h"
#include <cstdlib> // rand()関数を使用するためのヘッダー
#include <ctime>   // time()関数を使用するためのヘッダー

#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"


//コンストラクタ
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1), ItemKill(false)
{
}

//初期化
void KeyItem::Initialize()
{
    // モデルデータのロード
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);

    // 初期位置のランダム設定
    transform_.position_ = { (float)(rand() % 45 + 1), 1, (float)(rand() % 45 + 1) };

    // 回転とスケールの設定
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2, 0.2, 0.2 };

    // 20の間隔で座標を調整
    AdjustPositionWithGap(15.0f);

    // 衝突判定用のボックスコライダーの作成と追加
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);
}

// 20の間隔で座標を調整する関数
void KeyItem::AdjustPositionWithGap(float gap)
{
    int gapCountX = static_cast<int>(transform_.position_.x / gap);
    int gapCountZ = static_cast<int>(transform_.position_.z / gap);

    transform_.position_.x = gapCountX * gap + gap / 2.0f;
    transform_.position_.z = gapCountZ * gap + gap / 2.0f;
}

//更新
void KeyItem::Update()
{
    
}

//描画
void KeyItem::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}   

//開放
void KeyItem::Release()
{
}

void KeyItem::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        //当たったときの処理
        //pTarget->KillMe();//当たった弾を消す
        this->KillMe();//自分を消す
    }
}
