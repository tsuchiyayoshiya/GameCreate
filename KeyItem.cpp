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

    // 初期位置のランダム設定
    do {
        transform_.position_ = { (float)(rand() % 45 + 1), 1, (float)(rand() % 45 + 1) };
    } while (IsPositionTooCloseToOtherModels() || IsPositionInsideWalls());


    // 回転とスケールの設定
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2, 0.2, 0.2 };

    // 20の間隔で座標を調整
    AdjustPositionWithGap(15.0f);

    // 衝突判定用のボックスコライダーの作成と追加
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);
}

bool KeyItem::IsPositionTooCloseToOtherModels() const
{
    const float minDistance = 20.0f; // モデル間の最小距離

    // 他のKeyItemオブジェクトとの距離を計算
    for (const auto& gameObject : GetParent()->GetChildren()) {
        if (gameObject != this && gameObject->GetObjectName() == "KeyItem") {
            const KeyItem* otherKeyItem = dynamic_cast<KeyItem*>(gameObject);
            if (otherKeyItem) {
                float distance = XMVectorGetX(XMVector3Length(XMLoadFloat3(&transform_.position_) - XMLoadFloat3(&otherKeyItem->transform_.position_)));
                if (distance < minDistance) {
                    return true; // 近すぎる場合はtrueを返す
                }
            }
        }
    }

    return false; // 近すぎない場合はfalseを返す
}

// 20の間隔で座標を調整する関数
void KeyItem::AdjustPositionWithGap(float gap)
{
    int gapCountX = static_cast<int>(transform_.position_.x / gap);
    int gapCountZ = static_cast<int>(transform_.position_.z / gap);

    transform_.position_.x = gapCountX * gap + gap / 2.0f;
    transform_.position_.z = gapCountZ * gap + gap / 2.0f;
}

// 壁に埋まっていないかを判定する関数
bool KeyItem::IsPositionInsideWalls() const
{
    const float wallX = 50.0f; // 壁のX方向位置
    const float wallZ = 50.0f; // 壁のZ方向位置
    const float wallSize = 2.0f; // 壁のサイズ

    if (transform_.position_.x > wallX - wallSize && transform_.position_.x < wallX + wallSize &&
        transform_.position_.z > wallZ - wallSize && transform_.position_.z < wallZ + wallSize) {
        return true; // 壁に埋まっている場合はtrueを返す
    }

    return false; // 壁に埋まっていない場合はfalseを返す
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
