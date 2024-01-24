#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"

class KeyItem : public GameObject
{
	int hModel_;
	bool ItemKill;
	Stage* pStage;
public:

	enum ProgressKey
	{
		NoCatchKey, //�L�[���҂��Ă�����
		CatchKey, //�L�[���������Ă�����
	};

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	KeyItem(GameObject* parent);

	//������
	void Initialize() override;

	bool IsPositionTooCloseToOtherModels() const;

	bool IsPositionInsideWalls() const;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
   //�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;
};