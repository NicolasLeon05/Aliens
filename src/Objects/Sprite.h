#pragma once
#include "raylib.h"

namespace Sprite
{
	struct Sprite
	{
		Texture2D texture;
		Rectangle source;
		Rectangle destination;
		float scale;
		float rotation;
	};
}
