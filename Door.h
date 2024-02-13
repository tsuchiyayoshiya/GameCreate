#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Door : public GameObject
{
	int hModel_;
	int hPict_;
	bool Open_;
	float Timer = 0.0f; // Timer の初期化
protected:
	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Door(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};