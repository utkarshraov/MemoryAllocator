#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include<string>
#include "MemoryManagement.h"
using namespace Engine;

class Monster : GameObject {
	
	
public:
	char * name;
	Monster(char * monName);

	bool areYouFoodYet(Vector2);
	
};