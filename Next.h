#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Next : public GameObject
{
	int hPict_;
	float Timer;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Next(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};