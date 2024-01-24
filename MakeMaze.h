#pragma once
#include "Engine/GameObject.h"
class MakeMaze :public GameObject
{
private:
	int x = 50;
	int z = 50;
public:
	
	void Release() override;
};

