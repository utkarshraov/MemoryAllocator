#pragma once
#include "Vector2.h"
#include"GameObject.h"
using namespace Engine;
using namespace std;

class Player : public GameObject {
	
public:
	string name;
	Player(Vector2 initPosition,string pName);
	void inputMove(char choice);
	void checkBounds();
};