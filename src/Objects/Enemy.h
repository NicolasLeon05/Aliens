#pragma once
#include "raylib.h"
#include "Circle.h"
#include <vector>

using namespace std;

namespace Enemy
{
	const int startingEnemies = 70;
	const float totalSpeed = 80.0f;

	enum class Size
	{
		SpaceShip, BigMetalPiece, SmallMetalPiece
	};

	struct Enemy
	{
		Size size;
		/*Texture2D sprite;
		Rectangle source;
		Rectangle destination;
		float scale;
		float rotation;
		*/

		Circle::Circle collisionShape;
		Vector2 speed;

		bool isActive;
	};

	extern vector <Enemy> enemies;
	//extern Enemy enemies[maxEnemies];

	void Init();
	void CreateEnemies();
	void Draw();

	void DivideEnemy(Enemy enemy);
}