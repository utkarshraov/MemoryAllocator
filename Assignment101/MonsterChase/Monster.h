#pragma once
#include "Vector2.h"
using namespace Engine;

class Monster {
	
	
public:
	Vector2 currentLocation;
	char monsterName[15];
	Monster();
	void moveMonster();
	bool areYouFoodYet(Vector2);
	Vector2 getLocation();
};