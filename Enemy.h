#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Enemy : public GameObject
{
	int hModel_[6];    //画像番号
	bool turn;
	float playerX;
	int movementCount;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;
};