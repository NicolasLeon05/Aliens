#pragma once

#include "raylib.h"

namespace Player
{
	struct Player
	{
		Texture2D sprite;
		Rectangle source;
		Rectangle destination;

		Vector2 pos;
		float scale;
		float rotation;
	};

	extern Player player;

	void Init();

	void Draw();
}
