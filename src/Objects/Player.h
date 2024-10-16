#pragma once

#include "raylib.h"

#include "Rec.h"

namespace Player
{
	struct Player
	{
		Texture2D sprite;
		float scale;

		float x;
		float y;
	};

	extern Player player;

	void Init();

	void Draw(float rotation);
}
