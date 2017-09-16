#pragma once
#include "Vector2.h"
using namespace Engine;

class Player {
	
public:
	Vector2 currentLocation;
	char playerName[15];
	Player();
	int updateLocation(char);
	void setPosition(Vector2);

};