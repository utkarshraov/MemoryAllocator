#pragma once
#include "Vector2.h"

using namespace Engine;

class GameObject
{
protected:
	Vector2 position;
	
	
public:
	GameObject();
	GameObject(Vector2 initPosition);
	GameObject(const GameObject  & object);
	GameObject(GameObject && object);
	inline void setPosition(Vector2 pos)
	{
		position = pos;
	}
	inline Vector2 getPosition() const
	{
		return position;
	}
	inline void moveGameObject(Vector2 direction)
	{
		position = position + direction;
	}
	GameObject & operator=(const GameObject & object);
	GameObject & GameObject::operator=(GameObject && object);
};

GameObject & GameObject::operator=(const GameObject & object)
{
	//assignment operator
	setPosition(object.getPosition());
}