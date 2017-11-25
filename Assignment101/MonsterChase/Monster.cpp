#include "Vector2.h"
#include "Monster.h"
#include<stdlib.h>
#pragma once


Monster::Monster(char * monName)
{
	Monster::position.setX(rand() % 50);
	Monster::position.setY(rand() % 50);
	//name = reinterpret_cast<char *>(operator new(sizeof(monName)));
	//*name = *monName;
}




bool Monster::areYouFoodYet(Vector2 pos) {
	return false;
}



	
