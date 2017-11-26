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
	GameObject(GameObject *object);
	inline void setPosition(Vector2 pos)
	{
		position = pos;
	}
	inline Vector2 getPosition()
	{
		return position;
	}
	inline void moveGameObject(Vector2 direction)
	{
		position = position + direction;
	}
};