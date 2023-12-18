#include "BackGround.h"
#include "Engine/Image.h"

//コンストラクタ
BackGround::BackGround(GameObject* parent)
	: GameObject(parent, "BackGround"),hPict_(-1)
{
}

//初期化
void BackGround::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("donut.jpg");
    assert(hPict_ >= 0);
}

//更新
void BackGround::Update()
{
}

//描画
void BackGround::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//開放
void BackGround::Release()
{
}
