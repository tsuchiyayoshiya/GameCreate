#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Stage2 : public GameObject
{
	int hModel_;
	
	//マップの自動生成(勝手に自分がやってるだけなので,はい...)
	using vsize_t = std::vector<size_t>;
	using vvsize_t = std::vector<vsize_t>;

	//生成チェック
	const bool mapCheck(const vvsize_t& map_) {
		if (map_.size() <= 2 || map_.data()->size() <= 2) return false;
		if ((map_.size() & 1) == 0 || (map_.data()->size() & 1) == 0) return false;
		return true;
	}

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage2(GameObject* parent);

	//初期化
	void Initialize() override;

	void mazeDig(vvsize_t& map_, size_t x_, size_t y_, const size_t id_wall_, const size_t id_empty_);

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};