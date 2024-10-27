#include "Enemy.h"

#include <iostream>

#include "Utils.h"

using namespace Utils;

namespace Enemy
{
	vector <Enemy> enemies;

	static const float spaceShipSize = 22.0f;
	static const float bigMetalPieceSize = 16.0f;
	static const float smallMetalPieceSize = 10.0f;

	static void CreateEnemies();

	static Size SetRandomSize();

	static void SetSprite(Enemy& enemy);

	static void SetRandomPosition(Enemy& enemy);

	static void SetDirection(Enemy& enemy);

	static void SetSpriteProperties(Enemy& enemy);

	static void CreateDividedEnemy(Enemy original, Enemy& division);


	void Load()
	{
		if (enemies.empty())
		{
			CreateEnemies();
		}
		else
		{
			enemies.erase(enemies.begin(), enemies.end());
			CreateEnemies();
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


	void CreateEnemies()
	{
		for (int i = 0; i < startingEnemies; i++)
		{
			Enemy newEnemy;

			newEnemy.size = SetRandomSize();
			SetSprite(newEnemy);
			SetRandomPosition(newEnemy);
			SetDirection(newEnemy);
			SetSpriteProperties(newEnemy);
			newEnemy.isActive = true;

			enemies.push_back(newEnemy);
		}
	}

	Size SetRandomSize()
	{
		return Size(rand() % 3);
	}

	void SetSprite(Enemy& enemy)
	{
		switch (enemy.size)
		{
		case Size::SpaceShip:
		{
			enemy.sprite.texture = LoadTexture("res/Sprite/EnemySpaceship.png");
			enemy.collisionShape.radius = spaceShipSize;
			enemy.sprite.scale = 1.8f;
			break;
		}

		case Size::BigMetalPiece:
		{
			enemy.sprite.texture = LoadTexture("res/Sprite/BigMetalPiece.png");
			enemy.collisionShape.radius = bigMetalPieceSize;
			enemy.sprite.scale = 2.2f;
			break;
		}

		case Size::SmallMetalPiece:
		{
			enemy.sprite.texture = LoadTexture("res/Sprite/SmallMetalPiece.png");
			enemy.collisionShape.radius = smallMetalPieceSize;
			enemy.sprite.scale = 1.6f;
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

		// Calcular el ángulo hacia la posición objetivo
		float angle = CalculateAngleBetweenPoints(enemy.collisionShape.center, targetPosition);

		// Establecer la velocidad
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
		SetSprite(division);
		SetSpriteProperties(division);
		division.isActive = true;
	}
}

