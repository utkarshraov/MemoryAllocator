#include "Player.h"
#include "Vector2.h"
#include<stdlib.h>
#include "DebugStatement.h"
#include<stdio.h>
#include "GameObject.h"
#include<string>




using namespace Engine;

Player::Player(Vector2 initPosition, string pName)
{
	position = initPosition;
	name = pName;
}
void Player::inputMove(char choice)
{
	switch (choice)
	{
	case 'w':
		GameObject::moveGameObject(Vector2(0,1));
		break;
	case 'a':
		GameObject::moveGameObject(Vector2(-1,0));
		break;
	case 's':
		GameObject::moveGameObject(Vector2(0,-1));
		break;
	case 'd':
		GameObject::moveGameObject(Vector2(1,0));
		break;
	}
}
void Player::checkBounds()
{
	if (position.getX() < 0)
		position.setX(0);
	if (position.getX() > 100)
		position.setX(100);
	if (position.getY() < 0)
		position.setY(0);
	if (position.getY() > 100)
		position.setY(100);
}

