#include "Vector2.h"


namespace Engine
{

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
		


	
	
	Vector2 operator+(Vector2 const &lhs, Vector2 const &rhs)
	{	
		Vector2 temp;
		temp.setX(lhs.getX() + rhs.getX());
		temp.setY(lhs.getY() + rhs.getY());
		return  temp;
	}

}