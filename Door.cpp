#include "Door.h"
#include "Player.h"

#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Door::Door(GameObject* parent)
    : GameObject(parent, "Door"), hModel_(-1), hPict_(-1), Open_(false), Timer(0.0f) // Timer を初期化
{
}

//初期化
void Door::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 49, 0, 49};
    hModel_ = Model::Load("door.fbx");
    assert(hModel_ >= 0);
    //画像データのロード
    hPict_ = Image::Load("OpenDoor.png");
    assert(hPict_ >= 0);
}

//更新
void Door::Update()
{
   

    //鍵をすべて所得した時の処理
    Player* pPlayer = (Player*)FindObject("Player");
    if (pPlayer->getItemCount() == 11)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.5, 0.5, 0.5));
        AddCollider(collision);
        Open_ = true;
    }
}

//描画
void Door::Draw()
{
    Transform pict;
    if (Open_ == true)
    {
        Timer += 1.0f;

        if (Timer < 60) // Timer が 60 未満の場合にのみ画像を描画する
        {
            Image::SetTransform(hPict_, pict);
            Image::Draw(hPict_);
        }
    }
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    
}

void Door::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_NEXT);
    }
}

//開放
void Door::Release()
{
}
