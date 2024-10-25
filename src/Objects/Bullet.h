#pragma once

#include "raylib.h"

#include "Circle.h"

namespace Bullet
{
	const int maxBullets = 40;

	struct Bullet
	{
		Circle::Circle shape;
		Vector2 speed;
		Color color;
		bool isActive;
	};

	extern Bullet bullets[maxBullets];

	void Load();

	void Update();

	void Draw();
}