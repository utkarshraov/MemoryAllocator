#include "Vector2.h"


namespace Engine
{
	class Vector2 {
		int xPosition;
		int yPosition;

	public:
		int getX() {
			return xPosition;
		}

		int getY() {
			return yPosition;
		}

		void setX(int value)
		{
			xPosition = value;
		}

		void setY(int value)
		{
			yPosition = value;
		}

		Vector2(int xValue, int yValue) {
			xPosition = xValue;
			yPosition = yValue;
		}
		Vector2() {};


	
	};
	Vector2 operator +(Vector2 const &lhs, Vector2 const &rhs)
	{
		return(Vector2(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY()));
	}
}