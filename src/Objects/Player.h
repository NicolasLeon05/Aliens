#pragma once

#include "raylib.h"

#include "Rec.h"

namespace Player
{
	struct Player
	{
		MyRec::Rec rec;
		Texture2D sprite;
		Color color;
	};

	extern Player player;

	void Init();

	void Draw();
}
