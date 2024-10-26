#pragma once
#include <vector>

#include "raylib.h"

#include "Circle.h"

using namespace std;

namespace Enemy
{
	const int startingEnemies = 50;
	const float totalSpeed = 80.0f;

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

		Circle::Circle collisionShape;
		Vector2 speed;

		bool isActive;
	};

	extern vector <Enemy> enemies;

	void Load();
	void Draw();

	void DivideEnemy(Enemy enemy);
}