#include "Vector2.h"
#include<stdlib.h>

class Monster
{
public:


	Vector2 currentLocation;
	char monsterName[15];

	Vector2 getLocation()
	{
		return currentLocation;
	}

	Monster()
	{
		currentLocation.setX(rand() % 50);
		currentLocation.setY(rand() % 50);
	}

	void moveMonster()
	{
		int dir = rand() % 4;
		switch (dir)
		{
		case 0: currentLocation.setX(currentLocation.getX()+1);
			break;
		case 1: currentLocation.setX(currentLocation.getX()-1);
			break;
		case 2: currentLocation.setY(currentLocation.getY()+1);
			break;
		case 3: currentLocation.setY(currentLocation.getY()-1);
			break;
		}
		if (currentLocation.getX() > 49)
			currentLocation.setX(49);
		if (currentLocation.getX() <0)
			currentLocation.setX(0);
		if (currentLocation.getY() > 49)
			currentLocation.setY(49);
		if (currentLocation.getY() <0)
			currentLocation.setY(0);
	}
	bool areYouFoodYet(Vector2 playerLocation)
	{
		if (playerLocation.getX() == currentLocation.getX() && playerLocation.getY() == currentLocation.getY())
			return true;
		else
			return false;

	}
};