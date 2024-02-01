#include "Enemy.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include "Engine/Model.h"



//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    : GameObject(parent, "Enemy"), hModel_{-1}, turn(false), playerX(0.0f), movementCount(1.0)
{
}

//������
void Enemy::Initialize()
{
    transform_.scale_ = { 0.5,0.5,0.5 };
    transform_.position_ = { 4, 0, 4 };
    transform_.rotate_ = { 0, 180, 0 };

    for(int i = 0;i<6;i++)
    { 
    hModel_[i] = Model::Load("Enemy.fbx");
    assert(hModel_[i] >= 0);
    }
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
    for(int i = 0;i<6;i++)
    {
    Model::SetTransform(hModel_[i], transform_);
    Model::Draw(hModel_[i]);
    }
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
