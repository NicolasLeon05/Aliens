#pragma once

#include "raylib.h"
#include "Circle.h"

namespace Player
{
	struct Player
	{
		Texture2D sprite;
		Rectangle source;
		Rectangle destination;
		float scale;
		float rotation;
		
		Circle::Circle collisionShape;

		Vector2 pos;
		Vector2 speed;
		float maxAcceleration;
		float acceleration;
	};

	extern Player player;

	void Init();

	void Draw();
}
