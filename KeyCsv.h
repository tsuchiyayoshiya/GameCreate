#pragma once
#include "Engine/GameObject.h"

enum
{
	TYPE_KEY,
};

//テストシーンを管理するクラス
class KeyCsv : public GameObject
{
	int hModel_;    //モデル番号
	int** Key_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	KeyCsv(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};