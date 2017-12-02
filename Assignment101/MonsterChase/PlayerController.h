#pragma once
#include "GameObjectController.h"

class PlayerController : public GameObjectController
{
	void moveGameObject(GameObject *, Vector2);
	Vector2 getPosition(GameObject *);
	void moveFromInput(GameObject *, char input);
};

void PlayerController::moveGameObject(GameObject * player, Vector2 pos)
{
	player->setPosition(pos);
}

Vector2 PlayerController::getPosition(GameObject * player)
{
	return player->getPosition();
}
void PlayerController::moveFromInput(GameObject * player, char input)
{
	switch (input)
	{
	case 'w':
		player->moveGameObject(Vector2(0, 1));
		break;
	case 'a':
		player->moveGameObject(Vector2(-1, 0));
		break;
	case 's':
		player->moveGameObject(Vector2(0, -1));
		break;
	case 'd':
		player->moveGameObject(Vector2(1, 0));
		break;
	}
}