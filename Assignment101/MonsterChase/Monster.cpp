#include "Vector2.h"
#include "Monster.h"
#include<stdlib.h>

using namespace Engine;



	

	Vector2 Monster::getLocation()
	{
		return Monster::currentLocation;
	}

	Monster::Monster()
	{
		Monster::Monster::currentLocation.setX(rand() % 50);
		Monster::currentLocation.setY(rand() % 50);
	}

	void Monster::moveMonster()
	{
		int dir = rand() % 4;
		switch (dir)
		{
		case 0: Monster::currentLocation.setX(Monster::currentLocation.getX()+1);
			break;
		case 1: Monster::currentLocation.setX(Monster::currentLocation.getX()-1);
			break;
		case 2: Monster::currentLocation.setY(Monster::currentLocation.getY()+1);
			break;
		case 3: Monster::currentLocation.setY(Monster::currentLocation.getY()-1);
			break;
		}
		if (Monster::currentLocation.getX() > 49)
			Monster::currentLocation.setX(49);
		if (Monster::currentLocation.getX() <0)
			Monster::currentLocation.setX(0);
		if (Monster::currentLocation.getY() > 49)
			Monster::currentLocation.setY(49);
		if (Monster::currentLocation.getY() <0)
			Monster::currentLocation.setY(0);
	}
	bool Monster::areYouFoodYet(Vector2 playerLocation)
	{
		if (playerLocation.getX() == Monster::currentLocation.getX() && playerLocation.getY() == Monster::currentLocation.getY())
			return true;
		else
			return false;

	}
