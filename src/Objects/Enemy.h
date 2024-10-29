#pragma once
#include <vector>

#include "raylib.h"

#include "Objects/Sprite.h"
#include "Objects/Circle.h"

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

		Sprite::Sprite sprite;

		Circle::Circle collisionShape;
		Vector2 speed;

		bool isActive;

		int score;
	};

	extern vector <Enemy> enemies;

	void Load();
	void Draw();
	void Unload();

	void CreateEnemy();
	void DivideEnemy(Enemy enemy);
}