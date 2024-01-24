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
	
	//�}�b�v�̎�������(����Ɏ���������Ă邾���Ȃ̂�,�͂�...)
	using vsize_t = std::vector<size_t>;
	using vvsize_t = std::vector<vsize_t>;

	//�����`�F�b�N
	const bool mapCheck(const vvsize_t& map_) {
		if (map_.size() <= 2 || map_.data()->size() <= 2) return false;
		if ((map_.size() & 1) == 0 || (map_.data()->size() & 1) == 0) return false;
		return true;
	}

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage2(GameObject* parent);

	//������
	void Initialize() override;

	void mazeDig(vvsize_t& map_, size_t x_, size_t y_, const size_t id_wall_, const size_t id_empty_);

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};