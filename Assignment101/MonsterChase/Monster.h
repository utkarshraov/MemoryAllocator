#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include<string>
#include "MemoryManagement.h"
using namespace Engine;

class Monster :public GameObject {
	
	
public:
	char * name;
	Monster(char * monName);

	bool areYouFoodYet(Vector2);
	void moveMonster();
	
};