#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
	int hModel_;    //モデル番号
	int nowHp_, maxHp_;
	XMFLOAT3 prevPosition_;

	Stage* pStage;
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

	//何かに当たった
   //引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;
};