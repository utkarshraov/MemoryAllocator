#include "Vector2.h"


namespace Engine
{
	Vector2 Up = Vector2(0, 1);
	Vector2 Down = Vector2(0, -1);
	Vector2 Right = Vector2(1, 0);
	Vector2 Left = Vector2(-1, 0);
		int Vector2::getX() const{
			return xPosition;
		}

		int Vector2::getY() const{
			return yPosition;
		}

		void Vector2::setX(int value)
		{
			xPosition = value;
		}

		void Vector2::setY(int value)
		{
			yPosition = value;
		}

		Vector2::Vector2(int xValue, int yValue) 
		{
			xPosition = xValue;
			yPosition = yValue;
		}

		Vector2::Vector2() {};

		bool Vector2::checkEqual(Vector2 value)
		{
			if (xPosition == value.xPosition && yPosition == value.yPosition)
				return true;
			return false;
		}
		


	
	
		std::ostream & operator<<(std::ostream & stream, const Vector2 & vector)
		{
			
			stream << "("<<vector.getX() <<","<< vector.getY()<<")";
			return stream;
		}

		Vector2 operator+(Vector2 const &lhs, Vector2 const &rhs)
	{	
		Vector2 temp;
		temp.setX(lhs.getX() + rhs.getX());
		temp.setY(lhs.getY() + rhs.getY());
		return  temp;
	}

}