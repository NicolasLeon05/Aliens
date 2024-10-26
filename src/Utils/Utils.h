#pragma once
#include "raylib.h"

namespace Utils
{
	float CalculateAngleBetweenPoints(Vector2 from, Vector2 to);

	Vector2 CalculateVelocityFromAngle(float angleInDegrees, float totalSpeed);
}