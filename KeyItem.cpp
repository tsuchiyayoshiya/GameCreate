#include "KeyItem.h"
#include"BackGround.h"
#include"Player.h"
#include "Stage.h"
#include "Complete.h"
#include <cstdlib> // rand()�֐����g�p���邽�߂̃w�b�_�[
#include <ctime>   // time()�֐����g�p���邽�߂̃w�b�_�[

#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
KeyItem::KeyItem(GameObject* parent)
    : GameObject(parent, "KeyItem"), hModel_(-1), ItemKill(false)
{
    pStage = (Stage*)FindObject("Stage");
}

//������
void KeyItem::Initialize()
{
    // ���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Key.fbx");
    assert(hModel_ >= 0);

    // �����ʒu�̃����_���ݒ�
    do{
        transform_.position_ = { (float)(rand() % 51), 1, (float)(rand() % 51) };
    } while (pStage->IsWall(transform_.position_.x, transform_.position_.z));
    transform_.position_.x += 0.5;
    transform_.position_.z += 0.2;

    // ��]�ƃX�P�[���̐ݒ�
    transform_.rotate_.y = 180;
    transform_.scale_ = { 0.2, 0.2, 0.2 };

    // �Փ˔���p�̃{�b�N�X�R���C�_�[�̍쐬�ƒǉ�
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, -0.3f, 0), XMFLOAT3(0.5, 0.5, 0.5));
    AddCollider(collision);   
}

// �ǂɖ��܂��Ă��Ȃ����𔻒肷��֐�
bool KeyItem::IsPositionInsideWalls() const
{
    const float wallX = 50.0f; // �ǂ�X�����ʒu
    const float wallZ = 50.0f; // �ǂ�Z�����ʒu
    const float wallSize = 10.0f; // �ǂ̃T�C�Y

    if (transform_.position_.x > wallX - wallSize && transform_.position_.x < wallX + wallSize &&
        transform_.position_.z > wallZ - wallSize && transform_.position_.z < wallZ + wallSize) {
        return true; // �ǂɖ��܂��Ă���ꍇ��true��Ԃ�
    }

    return false; // �ǂɖ��܂��Ă��Ȃ��ꍇ��false��Ԃ�
}

//�X�V
void KeyItem::Update()
{
    
}

//�`��
void KeyItem::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}   

//�J��
void KeyItem::Release()
{
}

void KeyItem::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player")
    {
        //���������Ƃ��̏���
        //pTarget->KillMe();//���������e������
        this->KillMe();//����������
    }
}
