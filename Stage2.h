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

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage2(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};