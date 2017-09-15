#include "Player.h"
#include "Vector2.h"
#include<stdlib.h>

using namespace Engine;
class Player
{
public:
	Vector2 currentLocation;
	char playerName[15];

	Player()
	{
		currentLocation.setX(rand() % 50);
		currentLocation.setY(rand() % 50);
	}
	int updateLocation(char choice)
	{
		int success = 0;
		switch (choice)
		{
		case 'a': currentLocation.setX(currentLocation.getX() + 1);
			break;
		case 'w': currentLocation.setX(currentLocation.getY() + 1);
			break;
		case 'd': currentLocation.setX(currentLocation.getX() - 1);
			break;
		case 's': currentLocation.setX(currentLocation.getY() - 1);
			break;
		default: success = 1;
			break;
		}
		if(currentLocation.getX() > 49)
			currentLocation.setX(49);
		if (currentLocation.getX() <0)
			currentLocation.setX(0);
		if (currentLocation.getY() > 49)
			currentLocation.setY(49);
		if (currentLocation.getY() <0)
			currentLocation.setY(0);
	}

};