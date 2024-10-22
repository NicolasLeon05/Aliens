#pragma once
#include "raylib.h"

namespace Enemy
{
	const int maxEnemies = 30;
	extern Enemy enemies[maxEnemies];

	enum class Size
	{
		SpaceShip, BigMetalPiece, SmallMetalPiece
	};

	struct Enemy
	{
		Size size;
		Texture2D sprite;
		Rectangle source;
		Rectangle destination;
		float scale;
		float rotation;

		Vector2 pos;
	};

	void Init();
}