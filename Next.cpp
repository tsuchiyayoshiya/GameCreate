#include "Next.h"
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
Next::Next(GameObject* parent)
    : GameObject(parent, "Next"), hPict_(-1),Timer(1.0f)
{
}

//������
void Next::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("Next.png");
    assert(hPict_ >= 0);
}

//�X�V
void Next::Update()
{
    //float Timer = 0.0f;
    Timer += 1.0f;
    if (Timer == 5)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TEST);
    }
}

//�`��
void Next::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

//�J��
void Next::Release()
{
}
