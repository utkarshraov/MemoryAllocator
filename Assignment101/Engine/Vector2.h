#pragma once
#include<iostream>


namespace Engine
{

	class Vector2{
	private:
		int xPosition;
		int yPosition;
	public:
		
		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);
		Vector2(int, int);
		Vector2();
		bool checkEqual(Vector2);
		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
		friend Vector2 operator+(Vector2 const &lhs, Vector2 const &rhs);
	};
	
	
}