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
	inline void GameObject::setPosition(Vector2 pos)
	{
		position = pos;
	}
	inline Vector2 GameObject::getPosition()
	{
		return position;
	}
	inline void GameObject::moveGameObject(Vector2 direction)
	{
		position = position + direction;
	}
