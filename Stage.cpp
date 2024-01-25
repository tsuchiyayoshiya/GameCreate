#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "KeyItem.h"


//コンストラクタ
Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage"), hModel_{ -1, -1 }, table_(nullptr)
{

	CsvReader csv;
	csv.Load("map.csv");

	int width = csv.GetWidth();
	int height = csv.GetHeight();

	table_ = new int* [width];

	for (int i = 0; i < width; i++)
	{
		table_[i] = new int[height];
	}

	for (int x = 0; x < width; x++)
	{
		for (int z = 0; z < height; z++)
		{
			table_[x][height - 1 - z] = csv.GetValue(x, z);
		}
	}

}

//初期化
void Stage::Initialize()
{
	//KeyItem* pKeyItem = (KeyItem*)FindObject("KeyItem");
	//Instantiate<KeyItem>(this);
	const char* fileName[] = {
		"Floor1.fbx",
		"Wall.fbx",
	};

	//モデルデータのロード
	for (int i = 0; i < TYPE_MAX; i++)
	{
		hModel_[i] = Model::Load(fileName[i]);
		assert(hModel_[i] >= 0);
	}

}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
	Transform blockTrans;

	for (int x = 0; x < 51; x++)
	{
		for (int z = 0; z < 51; z++)
		{
			blockTrans.position_.x = x;
			blockTrans.position_.z = z;

			int type = table_[x][z];

			Model::SetTransform(hModel_[type], blockTrans);
			Model::Draw(hModel_[type]);
		}
	}
}

//開放
void Stage::Release()
{
	CsvReader csv;
	csv.Load("map.csv");

	int width = csv.GetWidth();
	int height = csv.GetHeight();

	for (int i = 0; i < width; i++)
	{
		delete[] table_[i];

	}
	delete[] table_;
}

bool Stage::IsWall(int x, int z)
{
	return table_[x][z];
}