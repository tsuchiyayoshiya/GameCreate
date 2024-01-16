#include "Enemy.h"
#include "Engine/Image.h"
#include "Engine/Model.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
    : GameObject(parent, "Enemy"), hModel_(-1),turn(false)
{
}

//初期化
void Enemy::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 10, 0, 4 };
    transform_.rotate_ = { 0, 180, 0 };

    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
}

//更新
void Enemy::Update()
{
    
  //  transform_.position_.x += 5;
    if (transform_.position_.x += 5)
    {
        turn = true;
    }
    else if (turn == true)
    {
        transform_.position_.x -= 0.5;
    }
    else
    {
        transform_.position_.x += 0.5;
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
