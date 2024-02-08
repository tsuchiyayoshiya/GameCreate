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



//�R���X�g���N�^
Title::Title(GameObject* parent)
    : GameObject(parent, "Title"), hPict_(-1), hPict1_(-1)
{
}

//������
void Title::Initialize()
{
   
    //�摜�f�[�^�̃��[�h
    hPict1_ = Image::Load("Title.jpg");
    assert(hPict1_ >= 0);
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Title.png");
    assert(hPict_ >= 0);
    //�摜�f�[�^�̃��[�h
    hPict2_ = Image::Load("Please.png");
    assert(hPict2_ >= 0);
}

//�X�V
void Title::Update()
{
    if (Input::IsKey(DIK_RETURN))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TEST);
    }
}

//�`��
void Title::Draw()
{
    Image::SetTransform(hPict1_, transform_);
    Image::Draw(hPict1_);
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
    Transform Plz;
    Plz.position_.y = -0.5;
    Image::SetTransform(hPict2_, Plz);
    Image::Draw(hPict2_);
}

//�J��
void Title::Release()
{
}
