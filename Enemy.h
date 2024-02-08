#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Enemy : public GameObject
{
	int hModel_;    
	int hModel_1;
	int hModel_2;
	int hModel_3;
	int hModel_4;
	int hModel_5;
	bool turn;
	float playerX;
	int movementCount;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Enemy(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;
};