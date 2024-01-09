#include "KeyItem.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include "Complete.h"

#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"


//コンストラクタ
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1),ItemKill(false)
{
}

//初期化
void KeyItem::Initialize()
{
    transform_.position_ = { (float)(rand() % 12 + 1),1,(float)(rand() % 8ddddddddd + 2) };
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2,0.2,0.2 };

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);
}

//更新
void KeyItem::Update()
{
    bool yPosition = false;
    /*
    transform_.position_.y += 0.01f;
    if (transform_.position_.y == 1)
    {
        yPosition = true;
    }
    else if (yPosition = true)
    {
        transform_.position_.y -= 0.01f;
    }
    */
}

//描画
void KeyItem::Draw()
{
    
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

    
    /*
    Transform aform, bform,cform,dform,eform;
    aform.position_ = { 4,1,5 };
    aform.rotate_.y = 180;
    aform.scale_ = { 0.2,0.2,0.2 };
    Model::SetTransform(hModel_, aform);
    Model::Draw(hModel_);
    bform.position_ = { 3,1,5 };
    bform.rotate_.y = 180;
    bform.scale_ = { 0.2,0.2,0.2 };
    Model::SetTransform(hModel_, bform);
    Model::Draw(hModel_);
    cform.position_ = { 2,1,5 };
    cform.rotate_.y = 180;
    cform.scale_ = { 0.2,0.2,0.2 };
    Model::SetTransform(hModel_, cform);
    Model::Draw(hModel_);
    dform.position_ = { 1,1,5 };
    dform.rotate_.y = 180;
    dform.scale_ = { 0.2,0.2,0.2 };
    Model::SetTransform(hModel_, dform);
    Model::Draw(hModel_);
    eform.position_ = { 0,1,5 };
    eform.rotate_.y = 180;
    eform.scale_ = { 0.2,0.2,0.2 };
    Model::SetTransform(hModel_, eform);
    Model::Draw(hModel_);
    */
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

        ItemKill = true;
    }
}
/*
void KeyItem::CheckSkill()
{
    if (ItemKill == true)
    {
        Instantiate<KeyItem>(this);
    }
}
*/