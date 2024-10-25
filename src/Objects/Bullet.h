#pragma once

#include "Circle.h"

namespace Bullet
{
	const int maxBullets = 40;

	struct Bullet
	{
		Circle::Circle shape;
		Vector2 speed;
		bool isActive;
	};

	extern Bullet bullets[maxBullets];

	void Update();

	void Draw();
}