#pragma once
#include "Engine/GameObject.h"

enum
{
	TYPE_FLOOR,
	TYPE_WALL,
	TYPE_KEY,
	TYPE_MAX
};

//テストシーンを管理するクラス
class Stage : public GameObject
{
	int hModel_[TYPE_MAX];    //モデル番号

	int** table_;


public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;


	//指定した位置が通れるか通れないか調べる
		//引数 : x, z	調べる位置
		//戻値 : 通れない = true / 通れる = false
	bool IsWall(int x, int z);
};