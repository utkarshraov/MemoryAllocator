#pragma once
#include "Vector2.h"
#include"GameObject.h"
using namespace Engine;

class Player : GameObject {
	
public:
	char * name;
	Player(Vector2 initPosition,char * pName);
	
	
};