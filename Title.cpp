#include "Title.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include"KeyItem.h"
#include"Door.h"
#include"Enemy.h"

#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"



//コンストラクタ
Title::Title(GameObject* parent)
    : GameObject(parent, "Title"), hPict_(-1), hPict1_(-1)
{
}

//初期化
void Title::Initialize()
{
    //画像データのロード
    hPict1_ = Image::Load("Title.jpg");
    assert(hPict1_ >= 0);
    //画像データのロード
    hPict_ = Image::Load("Title.png");
    assert(hPict_ >= 0);
}

//更新
void Title::Update()
{
    if (Input::IsKey(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TEST);
    }
}

//描画
void Title::Draw()
{
    Image::SetTransform(hPict1_, transform_);
    Image::Draw(hPict1_);
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
    
}

//開放
void Title::Release()
{
}
