#include "Enemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include "Engine/Model.h"



//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    : GameObject(parent, "Enemy"), hModel_(-1), turn(false), playerX(0.0f), movementCount(1.0)
{
}

//������
void Enemy::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 4, 0, 4 };
    transform_.rotate_ = { 0, 180, 0 };
 
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
    hModel_1 = Model::Load("Enemy.fbx");
    assert(hModel_1 >= 0);
    hModel_2 = Model::Load("Enemy.fbx");
    assert(hModel_2 >= 0);
    hModel_3 = Model::Load("Enemy.fbx");
    assert(hModel_3 >= 0);
    hModel_4 = Model::Load("Enemy.fbx");
    assert(hModel_4 >= 0);
    hModel_5 = Model::Load("Enemy.fbx");
    assert(hModel_5 >= 0);
    
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.8, 0.8, 0.8));
    AddCollider(collision);
}

//�X�V
void Enemy::Update()
{

    // 1�񓮂����Ƃɕϐ��𑝉�
     // movementCount�������ő���������
    movementCount += 1.0f;

    // movementCount��60�𒴂�����turn��true�ɂ�
    if (movementCount > 30.0f){
        turn = true;
    }
    if (movementCount > 60.0f)
    {
        movementCount = 0.0f;
        turn = false;
    }
    // turn��true�̏ꍇ�A�v���C���[�����Ɉړ�
    if (turn){
        transform_.position_.x -= 0.1f;
    }
    // turn��false�̏ꍇ�A�v���C���[���E�Ɉړ�
    else {
        transform_.position_.x += 0.1f;
    }
}

//�`��
void Enemy::Draw()
{
    Transform E1, E2, E3, E4, E5;

    E1.position_ = { 4, 0, 8 };
    E1.scale_ = { 0.5,0.5,0.5 };
    E1.rotate_ = { 0,180,0 };

    E2.position_ = {};

    

    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    Model::SetTransform(hModel_1, E1);
    Model::Draw(hModel_1);
    Model::SetTransform(hModel_2, E2);
    Model::Draw(hModel_2);
    Model::SetTransform(hModel_3, E3);
    Model::Draw(hModel_3);
    Model::SetTransform(hModel_4, E4);
    Model::Draw(hModel_4);
    Model::SetTransform(hModel_5, E5);
    Model::Draw(hModel_5);
}

//�����ɓ�������
void Enemy::OnCollision(GameObject* pTarget)
{
    //���������Ƃ��̏���
    //�e�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Player")
    {
        this->KillMe();
    }
}

//�J��
void Enemy::Release()
{
}
