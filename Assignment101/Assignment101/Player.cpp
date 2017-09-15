#include "Player.h"
#include "Vector2.h"

using namespace Engine;
class Player
{
public:
	Vector2 currentLocation;
	char playerName[15];

	Player()
	{
		currentLocation.xPos = rand() % 50;
		currentLocation.yPos = rand() % 50;
	}
	int updateLocation(char choice)
	{
		int success = 0;
		switch (choice)
		{
		case 'a': currentLocation.xPos--;
			break;
		case 'w': currentLocation.yPos++;
			break;
		case 'd': currentLocation.xPos++;
			break;
		case 's': currentLocation.yPos--;
			break;
		default: success = 1;
			break;
		}
		if (currentLocation.xPos < 0)
			currentLocation.xPos = 0;
		if (currentLocation.xPos >49)
			currentLocation.xPos = 49;
		if (currentLocation.yPos < 0)
			currentLocation.yPos = 0;
		if (currentLocation.yPos > 49)
			currentLocation.yPos = 49;
		return success;
	}

};