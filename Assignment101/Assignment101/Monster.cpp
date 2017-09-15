class Monster
{
public:


	coordinate currentLocation;
	char monsterName[15];

	coordinate getLocation()
	{
		return currentLocation;
	}

	Monster()
	{
		currentLocation.xPos = rand() % 50;
		currentLocation.yPos = rand() % 50;
	}

	void moveMonster()
	{
		int dir = rand() % 4;
		switch (dir)
		{
		case 0: currentLocation.xPos += 1;
			break;
		case 1: currentLocation.xPos -= 1;
			break;
		case 2: currentLocation.yPos += 1;
			break;
		case 3: currentLocation.yPos -= 1;
			break;
		}
		if (currentLocation.xPos > 49)
			currentLocation.xPos = 49;
		if (currentLocation.xPos <0)
			currentLocation.xPos = 0;
		if (currentLocation.yPos > 49)
			currentLocation.yPos = 49;
		if (currentLocation.yPos <0)
			currentLocation.yPos = 0;
	}
	bool areYouFoodYet(coordinate playerLocation)
	{
		if (playerLocation.xPos == currentLocation.xPos && playerLocation.yPos == currentLocation.yPos)
			return true;
		else
			return false;

	}
};