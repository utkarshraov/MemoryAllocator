#pragma once
#include "Vector2.h"
#include "GameObject.h"


using namespace Engine;


GameObject::GameObject()
	{
		position.setX(0);
		position.setY(0);
	}
GameObject::GameObject(Vector2 initPosition)
	{
		position = initPosition;
	}
GameObject::GameObject(GameObject * object)
{
	//copy constructor
	position = object->getPosition();
}


