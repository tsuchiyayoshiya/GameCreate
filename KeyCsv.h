#pragma once
#include "Engine/GameObject.h"

enum
{
	TYPE_KEY,
};

//�e�X�g�V�[�����Ǘ�����N���X
class KeyCsv : public GameObject
{
	int hModel_;    //���f���ԍ�
	int** Key_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	KeyCsv(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};