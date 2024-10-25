#pragma once

#include "raylib.h"

#include "Circle.h"

namespace Bullet
{

	struct Bullet
	{
		Circle::Circle shape;
		Vector2 speed;
		Color color;
		bool isActive;
	};

	void Load(Bullet& bullet);

	void Draw(Bullet bullet);
}