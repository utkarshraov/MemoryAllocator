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
GameObject::GameObject(const GameObject & object)
{
	//copy constructor
	Vector2(object.getPosition());
}
GameObject::GameObject(GameObject && object)
{
	//Move Constructor
	position = Vector2(object.getPosition());
}

GameObject & GameObject::operator=(GameObject && object)
{
	//move assignment operator
	std::swap(position, object.getPosition());
	return *this;
}
GameObject & GameObject::operator=(const GameObject & object)
{
	//assignment operator
	setPosition(object.getPosition());
	return *this;
}

