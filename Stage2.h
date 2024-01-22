#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Stage2 : public GameObject
{
	int hModel_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage2(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};