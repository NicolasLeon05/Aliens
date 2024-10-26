#include "Utils.h"
#include <cmath>

namespace Utils
{
	float CalculateAngleBetweenPoints(Vector2 from, Vector2 to)
	{
		Vector2 delta = { to.x - from.x, to.y - from.y };

		float angle = atan(delta.y / delta.x);

		//Convert to degrees
		angle *= (180 / PI);

		//Check cuadrant variants
		if (delta.x < 0)
			angle += 180.0f;
		else if (delta.y < 0)
			angle += 360.0f;

		return angle;
	}

	Vector2 CalculateVelocityFromAngle(float angleInDegrees, float totalSpeed)
	{
		float angleInRadians = angleInDegrees * (PI / 180);

		Vector2 velocity = { 
			totalSpeed * cos(angleInRadians), 
			totalSpeed * sin(angleInRadians) 
		};

		return velocity;
	}
}