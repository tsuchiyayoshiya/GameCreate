#include "KeyCsv.h"

#include "Engine/CsvReader.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"



//�R���X�g���N�^
KeyCsv::KeyCsv(GameObject* parent)
    : GameObject(parent, "KeyCsv"), hModel_(-1), Key_(nullptr)
{
    CsvReader csv;
    csv.Load("map2.csv");

    int width = csv.GetWidth();
    int height = csv.GetHeight();

    Key_ = new int* [width];

	for (int i = 0; i < width; i++)
	{
		Key_[i] = new int[height];
	}

	for (int x = 0; x < width; x++)
	{
		for (int z = 0; z < height; z++)
		{
			Key_[x][height - 1 - z] = csv.GetValue(x, z);
		}
	}
}

//������
void KeyCsv::Initialize()
{
	const char* fileName[] = {
		"Floor1.fbx",
		"Key.fbx"
	};

	//���f���f�[�^�̃��[�h
	for (int i = 0; i < TYPE_KEY; i++)
	{
		hModel_ = Model::Load(fileName[i]);
		assert(hModel_ >= 0);
	}

}

//�X�V
void KeyCsv::Update()
{
}

//�`��
void KeyCsv::Draw()
{
	Transform keyTrans;

	for (int x = 0; x < 51; x++)
	{
		for (int z = 0; z < 51; z++)
		{
			keyTrans.position_.x = x;
			keyTrans.position_.z = z;

			int type = Key_[x][z];

			Model::SetTransform(hModel_, keyTrans);
			Model::Draw(hModel_);
		}
	}
}

//�J��
void KeyCsv::Release()
{
	CsvReader csv;
	csv.Load("map.csv");

	int width = csv.GetWidth();
	int height = csv.GetHeight();

	for (int i = 0; i < width; i++)
	{
		delete[] Key_[i];

	}
	delete[] Key_;
}
