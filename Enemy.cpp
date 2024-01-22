#include "Enemy.h"
#include "Engine/Image.h"
#include "Engine/Model.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    : GameObject(parent, "Enemy"), hModel_(-1),turn(false),playerX(0.0f),movementCount(1.0)
{
}

//初期化
void Enemy::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 4, 0, 4 };
    transform_.rotate_ = { 0, 180, 0 };

    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
}

//更新
void Enemy::Update()
{

    // 1回動くごとに変数を増加
     // movementCountを小数で増加させる
    movementCount += 1.0f;

    // movementCountが60を超えたらturnをtrueにし
    if (movementCount > 60.0f){
        turn = true;
    }
    if (movementCount > 120.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turnがtrueの場合、プレイヤーを左に移動
    if (turn){
        transform_.position_.x -= 0.1f;
    }
    // turnがfalseの場合、プレイヤーを右に移動
    else {
        transform_.position_.x += 0.1f;
    }
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Enemy::Release()
{
}
