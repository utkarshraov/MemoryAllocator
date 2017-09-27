#include "Player.h"
#include "Vector2.h"
#include<stdlib.h>
#include "DebugStatement.h"
#include<stdio.h>



using namespace Engine;



	Player::Player()
	{
		Player::currentLocation.setX(rand() % 50);
		Player::currentLocation.setY(rand() % 50);
	}
	void Player::updateLocation(char choice)
	{
		switch (choice)
		{
		case 'a': Player::currentLocation.setX(Player::currentLocation.getX() + 1);
					
			break;
		case 'w': Player::currentLocation.setX(Player::currentLocation.getY() + 1);
			break;
		case 'd': Player::currentLocation.setX(Player::currentLocation.getX() - 1);
			break;
		case 's': Player::currentLocation.setX(Player::currentLocation.getY() - 1);
			break;
		case 'q':
			exit(0);

		default: DEBUG_PRINT("Wrong option entered");
			EMIT_LOCATION();
			printf("\nINvalid option\n");
			break;
		}
		if(Player::currentLocation.getX() > 49)
			Player::currentLocation.setX(49);
		if (Player::currentLocation.getX() <0)
			Player::currentLocation.setX(0);
		if (Player::currentLocation.getY() > 49)
			Player::currentLocation.setY(49);
		if (Player::currentLocation.getY() <0)
			Player::currentLocation.setY(0);
	}

	void Player::setPosition(Vector2 position) {
		Player::currentLocation.setX(position.getX());
		Player::currentLocation.setY(position.getY());
	}

