#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"

class KeyItem : public GameObject
{
	int hModel_;
	bool ItemKill;
	Stage* pStage;
public:

	enum ProgressKey
	{
		NoCatchKey, //キーが待っている状態
		CatchKey, //キーを所持している状態
	};

	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	KeyItem(GameObject* parent);

	//初期化
	void Initialize() override;

	bool IsPositionTooCloseToOtherModels() const;

	bool IsPositionInsideWalls() const;

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