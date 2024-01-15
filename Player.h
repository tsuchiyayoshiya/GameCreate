#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
	int hModel_;    //モデル番号
	int nowHp_, maxHp_;
	bool ItemKill;
	XMFLOAT3 prevPosition_;

	Stage* pStage;

	Text* pText;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//void OnCollision(GameObject* pTarget);
};