#pragma once

namespace Engine
{
	class Vector2{
		int getX();
		int getY();
		void setX(int value);
		void setY(int value);

	}
	Vector2 operator+(&Vector2, &Vector2);
}