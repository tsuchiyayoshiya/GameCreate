#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
#include "Engine/Text.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
	int hModel_;    //���f���ԍ�
	int nowHp_, maxHp_;
	bool ItemKill;
	XMFLOAT3 prevPosition_;

	Stage* pStage;

	Text* pText;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//void OnCollision(GameObject* pTarget);
};