#include "Player.h"
#include "Vector2.h"
#include<stdlib.h>
#include "DebugStatement.h"
#include<stdio.h>
#include "GameObject.h"
#include<string>




using namespace Engine;



Player::Player(Vector2 initPosition, char * pName)
{
	position = initPosition;
	name = pName;
}

