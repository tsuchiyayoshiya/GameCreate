#pragma once
#include "Engine/GameObject.h"

enum
{
	TYPE_FLOOR,
	TYPE_WALL,
	TYPE_KEY,
	TYPE_MAX
};

//�e�X�g�V�[�����Ǘ�����N���X
class Stage : public GameObject
{
	int hModel_[TYPE_MAX];    //���f���ԍ�

	int** table_;


public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	//�w�肵���ʒu���ʂ�邩�ʂ�Ȃ������ׂ�
		//���� : x, z	���ׂ�ʒu
		//�ߒl : �ʂ�Ȃ� = true / �ʂ�� = false
	bool IsWall(int x, int z);
};