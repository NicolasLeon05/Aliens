#pragma once

#include "raylib.h"

#include "Sprite.h"
#include "Circle.h"

namespace Bullet
{

	struct Bullet
	{
		Sprite::Sprite sprite;
		Circle::Circle collisionShape;
		Vector2 speed;
		Color color;
		bool isActive;
	};

	void Load(Bullet& bullet);

	void Draw(Bullet bullet);
}