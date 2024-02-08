#include "Enemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include "Engine/Model.h"



//コンストラクタ
Enemy::Enemy(GameObject* parent) 
    : GameObject(parent, "Enemy"), hModel_(-1), hModel1_(-1), hModel2_(-1), hModel3_(-1), hModel4_(-1), hModel5_(-1), turn(false), playerX(0.0f), movementCount(1.0)
{
}

//初期化
void Enemy::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 1, 0, 7 };
    transform_.rotate_ = { 0, 180, 0 };
 
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
    hModel1_ = Model::Load("Enemy.fbx");
    assert(hModel1_ >= 0);
    hModel2_ = Model::Load("Enemy.fbx");
    assert(hModel2_ >= 0);
    hModel3_ = Model::Load("Enemy.fbx");
    assert(hModel3_ >= 0);
    hModel4_ = Model::Load("Enemy.fbx");
    assert(hModel4_ >= 0);
    hModel5_ = Model::Load("Enemy.fbx");
    assert(hModel5_ >= 0);
    for(int i = 0;i<6;i++)
    {
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.8, 0.8, 0.8));
    AddCollider(collision);
    }
}

//更新
void Enemy::Update()
{

    // 1回動くごとに変数を増加
     // movementCountを小数で増加させる
    movementCount += 1.0f;

    // movementCountが60を超えたらturnをtrueにし
    if (movementCount > 30.0f){
        turn = true;
    }
    if (movementCount > 60.0f)
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
    Transform E1, E2, E3, E4, E5;

    E1.position_ = { 40, 0, 8 };
    E1.scale_ = { 0.5,0.5,0.5 };
    E1.rotate_ = { 0,180,0 };

    E2.position_ = { 30, 0, 8 };
    E2.scale_ = { 0.5,0.5,0.5 };
    E2.rotate_ = { 0,180,0 };

    E3.position_ = { 6, 0, 8 };
    E3.scale_ = { 0.5,0.5,0.5 };
    E3.rotate_ = { 0,180,0 };

    E4.position_ = { 20, 0, 8 };
    E4.scale_ = { 0.5,0.5,0.5 };
    E4.rotate_ = { 0,180,0 };

    E5.position_ = { 8, 0, 8 };
    E5.scale_ = { 0.5,0.5,0.5 };
    E5.rotate_ = { 0,180,0 };

    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    Model::SetTransform(hModel1_, E1);
    Model::Draw(hModel1_);
    Model::SetTransform(hModel2_, E2);
    Model::Draw(hModel2_);
    Model::SetTransform(hModel3_, E3);
    Model::Draw(hModel3_);
    Model::SetTransform(hModel4_, E4);
    Model::Draw(hModel4_);
    Model::SetTransform(hModel5_, E5);
    Model::Draw(hModel5_);
}

//何かに当たった
void Enemy::OnCollision(GameObject* pTarget)
{
    //当たったときの処理
    //弾に当たったとき
    if (pTarget->GetObjectName() == "Player")
    {
        this->KillMe();
    }
}

//開放
void Enemy::Release()
{
}
