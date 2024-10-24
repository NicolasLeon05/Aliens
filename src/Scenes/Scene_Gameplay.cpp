#include "Scene_Gameplay.h"

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "math.h"

#include "SoundManager.h"

#include <iostream>

namespace PlayerNS = Player;
using namespace PlayerNS;

namespace EnemyNS = Enemy;
using namespace EnemyNS;

using namespace SoundManager;

using namespace std;


namespace Gameplay
{
	static Vector2 mousePosition;
	static float r;
	static float playerAngle; //Quizas tendria que ser una variable de player

	static Texture2D background;

	//Player movement
	static void SetPlayerRotation();
	static void SetPlayerAcceleration();
	static void MovePlayer();
	static void KeepPlayerOnScreen();

	//Enemies movement
	static void ManageEnemies();
	static void MoveEnemy(EnemyNS::Enemy& enemy);
	static void KeepEnemyOnScreen(EnemyNS::Enemy& enemy);

	//Collisions
	static bool PlayerEnemyAreColliding(EnemyNS::Enemy& enemy);

	void Init()
	{
		PlayerNS::Init();
		EnemyNS::Init();
		background = LoadTexture("res/Backgrounds/GameplayBackground.png");
	}

	void Update()
	{
		SetPlayerRotation();
		if (IsMouseButtonDown(1))
		{
			if (!IsSoundPlaying(accelerateSound))
				PlaySound(accelerateSound);

			SetPlayerAcceleration();
		}
		else
		{
			StopSound(accelerateSound);
		}

		MovePlayer();
		KeepPlayerOnScreen();

		ManageEnemies();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		PlayerNS::Draw();
		EnemyNS::Draw();
	}



	void SetPlayerRotation()
	{
		//Get polar coordinates of the mouse
		mousePosition = { GetMousePosition().x - player.pos.x, player.pos.y - GetMousePosition().y };

		//Get angle in radians
		playerAngle = atan(mousePosition.y / mousePosition.x);

		//Convert to degrees
		playerAngle *= (180 / PI);

		//Check cuadrant variants
		if (mousePosition.x < 0)
			playerAngle += 180.0f;
		else if (mousePosition.y < 0)
			playerAngle += 360.0f;

		//Assing player rotation
		player.rotation = -playerAngle + 90;
	}

	void SetPlayerAcceleration()
	{
		float angleInRadians = playerAngle * (PI / 180);

		player.speed.x += player.acceleration * cos(angleInRadians);
		player.speed.y += (-player.acceleration) * sin(angleInRadians);

		float speedMagnitude = static_cast <float> (sqrt(pow(player.speed.x, 2) + pow(player.speed.y, 2)));
		if (speedMagnitude > player.maxAcceleration) {
			player.speed.x *= (player.maxAcceleration / speedMagnitude);
			player.speed.y *= (player.maxAcceleration / speedMagnitude);
		}
	}

	void MovePlayer()
	{
#ifdef _DEBUG
		//cout << "speed x: " << player.speed.x << " speed y: " << player.speed.y << endl << endl;
#endif // _DEBUG

		player.pos.x += player.speed.x * GetFrameTime();
		player.pos.y += player.speed.y * GetFrameTime();

		player.destination.x = player.pos.x;
		player.destination.y = player.pos.y;

		player.collisionShape.center = player.pos;
	}

	void KeepPlayerOnScreen()
	{
		float spriteWidth = static_cast <float> (player.sprite.width) * player.scale / 2;
		float spriteHeight = static_cast <float> (player.sprite.height) * player.scale / 2;

		//Check x axis
		if (player.pos.x - spriteWidth > GetScreenWidth())
			player.pos.x = 0 - spriteWidth;
		else if (player.pos.x + spriteWidth < 0)
			player.pos.x = static_cast <float> (GetScreenWidth()) + spriteWidth;

		//Check y axis
		if (player.pos.y - spriteHeight > GetScreenHeight())
			player.pos.y = 0 - spriteHeight;
		else if (player.pos.y + spriteHeight < 0)
			player.pos.y = static_cast <float>(GetScreenHeight()) + spriteHeight;

		player.destination.x = player.pos.x;
		player.destination.y = player.pos.y;
	}

	void ManageEnemies()
	{
		for (int i = 0; i < static_cast <int>(enemies.size()); i++)
		{
			if (enemies[i].isActive)
			{
				MoveEnemy(enemies[i]);
				KeepEnemyOnScreen(enemies[i]);
				if (PlayerEnemyAreColliding(enemies[i]))
				{
					enemies[i].isActive = false;
					DivideEnemy(enemies[i]);
				}
			}
		}
	}

	void MoveEnemy(EnemyNS::Enemy& enemy)
	{
		enemy.collisionShape.center.x += enemy.speed.x * GetFrameTime();
		enemy.collisionShape.center.y += enemy.speed.y * GetFrameTime();
		enemy.collisionShape.center.x = enemy.collisionShape.center.x;
		enemy.collisionShape.center.y = enemy.collisionShape.center.y;
	}

	void KeepEnemyOnScreen(EnemyNS::Enemy& enemy)
	{
		//Check x axis
		if (enemy.collisionShape.center.x - enemy.collisionShape.radius > GetScreenWidth())
			enemy.collisionShape.center.x = 0 - enemy.collisionShape.radius;
		else if (enemy.collisionShape.center.x + enemy.collisionShape.radius < 0)
			enemy.collisionShape.center.x = static_cast <float> (GetScreenWidth()) + enemy.collisionShape.radius;

		//Check y axis
		if (enemy.collisionShape.center.y - enemy.collisionShape.radius > GetScreenHeight())
			enemy.collisionShape.center.y = 0 - enemy.collisionShape.radius;
		else if (enemy.collisionShape.center.y + enemy.collisionShape.radius < 0)
			enemy.collisionShape.center.y = static_cast <float>(GetScreenHeight()) + enemy.collisionShape.radius;

		enemy.collisionShape.center.x = enemy.collisionShape.center.x;
		enemy.collisionShape.center.y = enemy.collisionShape.center.y;
	}

	bool PlayerEnemyAreColliding(EnemyNS::Enemy& enemy)
	{
		float distX = player.collisionShape.center.x - enemy.collisionShape.center.x;
		float distY = player.collisionShape.center.y - enemy.collisionShape.center.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		return distance <= player.collisionShape.radius + enemy.collisionShape.radius;
	}

}