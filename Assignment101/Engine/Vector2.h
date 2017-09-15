#pragma once

namespace Engine
{
	class Vector2{
		int xPosition;
		int yPosition;
	public:
		
		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);
		Vector2(int, int);
		Vector2();

	};
	Vector2 operator+(Vector2 &, Vector2 &);
}