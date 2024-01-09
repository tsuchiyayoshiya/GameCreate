#pragma once
#include "Engine/GameObject.h"



//�e�X�g�V�[�����Ǘ�����N���X
class KeyItem : public GameObject
{
	int hModel_;
	bool ItemKill;
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

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
   //�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;

	//void CheckSkill();
};