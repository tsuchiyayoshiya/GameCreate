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
#include "Engine/SceneManager.h"


//コンストラクタ
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1), ItemKill(false)
{
    pStage = (Stage*)FindObject("Stage");
}

//初期化
void KeyItem::Initialize()
{
    // モデルデータのロード
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);

    // 初期位置のランダム設定
    transform_.position_ = { (float)(rand() % 45 + 1), 1, (float)(rand() % 45 + 1) };

    // 初期位置のランダム設定
    do {
        transform_.position_ = { (float)(rand() % 45 + 1), 1, (float)(rand() % 45 + 1) };
    } while (IsPositionInsideWalls());


    // 回転とスケールの設定
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2, 0.2, 0.2 };

    // 衝突判定用のボックスコライダーの作成と追加
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);
}

// 壁に埋まっていないかを判定する関数
bool KeyItem::IsPositionInsideWalls() const
{
    const float wallX = 50.0f; // 壁のX方向位置
    const float wallZ = 50.0f; // 壁のZ方向位置
    const float wallSize = 15.0f; // 壁のサイズ

    if (transform_.position_.x > wallX - wallSize && transform_.position_.x < wallX + wallSize &&
        transform_.position_.z > wallZ - wallSize && transform_.position_.z < wallZ + wallSize) {
        return true; // 壁に埋まっている場合はtrueを返す
    }

    return false; // 壁に埋まっていない場合はfalseを返す
}

//更新
void KeyItem::Update()
{
    GameObject* pGameObject = FindObject("Stage");
    
}

//描画
void KeyItem::Draw()
{
    /*
    const float wallX = 50.0f; // 壁のX方向位置
    const float wallZ = 50.0f; // 壁のZ方向位置
    const float wallSize = 15.0f; // 壁のサイズ
    const float wall
    if (pStage->IsWall(wallSize,))
    {

    }
    */
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
