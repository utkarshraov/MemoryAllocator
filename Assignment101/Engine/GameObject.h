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
	inline void setPosition(Vector2 pos);
	inline Vector2 getPosition();
	inline void moveGameObject(Vector2 direction);
};