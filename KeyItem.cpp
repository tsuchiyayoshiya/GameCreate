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
#include "Engine/CsvReader.h"


//コンストラクタ
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_{-1,-1}, ItemKill(false), table_(nullptr)
{
    CsvReader csv;
    csv.Load("map2.csv");


    int Key = csv.GetWidth();
    table_ = new int* [Key];
}

//初期化
void KeyItem::Initialize()
{
    transform_.position_ = { (float)(rand() % 12 + 1),1,(float)(rand() % 8 + 2) };
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2,0.2,0.2 };

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);

    const char* fileName[] = {
     "Key.fbx"
    };
    //モデルデータのロード
    for (int i = 0; i < TYPE_KEY; i++)
    {
        hModel_[i] = Model::Load(fileName[i]);
        assert(hModel_[i] >= 0);
    }
}

//更新
void KeyItem::Update()
{
    bool yPosition = false;   
}

//描画
void KeyItem::Draw()
{
    
    Transform blockTrans;

    for (int x = 0; x < 51; x++)
    {
        for (int z = 0; z < 51; z++)
        {
            blockTrans.position_.x = x;
            blockTrans.position_.z = z;

            int type = table_[x][z];



            Model::SetTransform(hModel_[type], blockTrans);
            Model::Draw(hModel_[type]);
        }
    }

    
    
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
