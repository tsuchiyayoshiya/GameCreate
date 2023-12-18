#include "Player.h"
#include "Engine/Image.h"

//コンストラクタ
Player::Player(GameObject* parent)
    : GameObject(parent, "Player"), hPict_(-1)
{
}

//初期化
void Player::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("Player.jpg");
    assert(hPict_ >= 0);
}

//更新
void Player::Update()
{
}

//描画
void Player::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void Player::Release()
{
}
