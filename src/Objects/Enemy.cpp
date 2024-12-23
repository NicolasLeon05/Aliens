#include "Enemy.h"

#include <iostream>

#include "Utils/Utils.h"

using namespace Utils;

namespace Enemy
{
	vector <Enemy> enemies;

	static const float spaceShipSize = 22.0f;
	static const float bigMetalPieceSize = 16.0f;
	static const float smallMetalPieceSize = 10.0f;

	static Texture2D spaceShipTexture;
	static Texture2D bigMetalPieceTexture;
	static Texture2D smallMetalPieceTexture;

	static Size SetRandomSize();

	static void SetSpriteAndScore(Enemy& enemy);

	static void SetRandomPosition(Enemy& enemy);

	static void SetDirection(Enemy& enemy);

	static void SetSpriteProperties(Enemy& enemy);

	static void CreateDividedEnemy(Enemy original, Enemy& division);


	void Load()
	{
		spaceShipTexture = LoadTexture("res/Sprite/EnemySpaceship.png");
		bigMetalPieceTexture = LoadTexture("res/Sprite/BigMetalPiece.png");
		smallMetalPieceTexture = LoadTexture("res/Sprite/SmallMetalPiece.png");

		if (!enemies.empty())
		{
			enemies.erase(enemies.begin(), enemies.end());
		}

		for (int i = 0; i < startingEnemies; i++)
		{
			CreateEnemy();
		}
	}

	void Draw()
	{
		for (int i = 0; i < static_cast<int> (enemies.size()); i++)
		{
			if (enemies[i].isActive)
			{
#ifdef _DEBUG
				//Draw CollisionShape
				int x = static_cast<int> (enemies[i].collisionShape.center.x);
				int y = static_cast<int> (enemies[i].collisionShape.center.y);
				float radius = enemies[i].collisionShape.radius;

				DrawCircle(x, y, radius, RED);
#endif // _DEBUG

				//Draw sprite
				Vector2 spriteCenter =
				{
					enemies[i].sprite.texture.height * enemies[i].sprite.scale / 2,
					enemies[i].sprite.texture.width * enemies[i].sprite.scale / 2
				};

				DrawTexturePro(enemies[i].sprite.texture,
					enemies[i].sprite.source,
					enemies[i].sprite.destination,
					spriteCenter,
					enemies[i].sprite.rotation,
					WHITE);

			}
		}
	}

	void Unload()
	{
		UnloadTexture(spaceShipTexture);
		UnloadTexture(bigMetalPieceTexture);
		UnloadTexture(smallMetalPieceTexture);

		enemies.erase(enemies.begin(), enemies.end());
	}

	void DivideEnemy(Enemy enemy)
	{
		if (enemy.size != Size::SmallMetalPiece)
		{
			Enemy division1;
			Enemy division2;

			switch (enemy.size)
			{
			case Size::SpaceShip:
			{
				division1.size = Size::BigMetalPiece;
				division2.size = Size::BigMetalPiece;
				break;
			}

			case Size::BigMetalPiece:
			{
				division1.size = Size::SmallMetalPiece;
				division2.size = Size::SmallMetalPiece;
				break;
			}

			default:
			{
				std::cout << "Error. Entro al default de AssignSize" << std::endl;
				break;
			}
			}

			CreateDividedEnemy(enemy, division1);
			CreateDividedEnemy(enemy, division2);

			enemies.push_back(division1);
			enemies.push_back(division2);
		}
	}

	void CreateEnemy()
	{
		Enemy newEnemy;

		newEnemy.size = SetRandomSize();
		SetSpriteAndScore(newEnemy);
		SetRandomPosition(newEnemy);
		SetDirection(newEnemy);
		SetSpriteProperties(newEnemy);
		newEnemy.isActive = true;

		enemies.push_back(newEnemy);
	}


	Size SetRandomSize()
	{
		return Size(rand() % 3);
	}

	void SetSpriteAndScore(Enemy& enemy)
	{
		switch (enemy.size)
		{
		case Size::SpaceShip:
		{
			enemy.sprite.texture = spaceShipTexture;
			enemy.collisionShape.radius = spaceShipSize;
			enemy.sprite.scale = 1.8f;
			enemy.score = 150;
			break;
		}

		case Size::BigMetalPiece:
		{
			enemy.sprite.texture = bigMetalPieceTexture;
			enemy.collisionShape.radius = bigMetalPieceSize - 3;
			enemy.sprite.scale = 2.2f;
			enemy.score = 100;
			break;
		}

		case Size::SmallMetalPiece:
		{
			enemy.sprite.texture = smallMetalPieceTexture;
			enemy.collisionShape.radius = smallMetalPieceSize - 1;
			enemy.sprite.scale = 1.6f;
			enemy.score = 50;
			break;
		}

		default:
		{
			std::cout << "Error. Entro al default de AssignSize" << std::endl;
			break;
		}
		}
	}

	void SetRandomPosition(Enemy& enemy)
	{
		enum class StartingPosition
		{
			Top, Bottom, Left, Right
		};

		float screenWidth = static_cast<float>(GetScreenWidth());
		float screenHeight = static_cast<float>(GetScreenHeight());

		StartingPosition startingPosition = StartingPosition(rand() % 4);

		switch (startingPosition)
		{
		case StartingPosition::Top:
		{
			enemy.collisionShape.center.y = -bigMetalPieceSize;
			enemy.collisionShape.center.x = static_cast<float> (rand() % GetScreenWidth());
			break;
		}

		case StartingPosition::Bottom:
		{
			enemy.collisionShape.center.y = screenHeight + bigMetalPieceSize;
			enemy.collisionShape.center.x = static_cast<float> (rand() % GetScreenWidth());
			break;
		}

		case StartingPosition::Left:
		{
			enemy.collisionShape.center.y = static_cast<float> (rand() % GetScreenHeight());
			enemy.collisionShape.center.x = -bigMetalPieceSize;
			break;
		}

		case StartingPosition::Right:
		{
			enemy.collisionShape.center.y = static_cast<float> (rand() % GetScreenHeight());
			enemy.collisionShape.center.x = screenWidth + bigMetalPieceSize;
			break;
		}

		default:
		{
			std::cout << "Error. entro al default" << std::endl;
			break;
		}
		}
	}

	void SetDirection(Enemy& enemy)
	{
		Vector2 targetPosition = {
			static_cast<float>(rand() % GetScreenWidth()),
			static_cast<float>(rand() % GetScreenHeight())
		};

		float angle = CalculateAngleBetweenPoints(enemy.collisionShape.center, targetPosition);

		enemy.speed = CalculateVelocityFromAngle(angle, totalSpeed);

	}

	void SetSpriteProperties(Enemy& enemy)
	{
		enemy.sprite.source =
		{
			0,
			0,
			static_cast<float>(enemy.sprite.texture.width),
			static_cast<float>(enemy.sprite.texture.height)
		};

		float destinationWidth = enemy.sprite.texture.width * enemy.sprite.scale;
		float destinationHeight = enemy.sprite.texture.height * enemy.sprite.scale;

		enemy.sprite.destination =
		{
			enemy.collisionShape.center.x,
			enemy.collisionShape.center.y,
			destinationWidth,
			destinationHeight
		};
	}

	void CreateDividedEnemy(Enemy original, Enemy& division)
	{
		division.collisionShape.center = original.collisionShape.center;
		division.collisionShape.center.x = original.collisionShape.center.x;
		division.collisionShape.center.y = original.collisionShape.center.y;

		SetDirection(division);
		SetSpriteAndScore(division);
		SetSpriteProperties(division);
		division.isActive = true;
	}
}

