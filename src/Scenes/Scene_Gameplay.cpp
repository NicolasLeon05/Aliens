#include "Scene_Gameplay.h"

#include <iostream>
#include <cmath>

#include "raylib.h"

#include "Player.h"
#include "Enemy.h"
#include "SoundManager.h"
#include "Utils.h"


namespace PlayerNS = Player;
namespace EnemyNS = Enemy;

using namespace PlayerNS;
using namespace EnemyNS;
using namespace SoundManager;
using namespace Utils;

using namespace std;


namespace Gameplay
{
	static float r;
	static float rotationAngle;
	static const float enemyRemovalTime = 5.0f;
	static float enemyRemovalCount = 0.0f;

	static Texture2D background;

	//Player
	static void SetPlayerRotation();
	static void SetPlayerAcceleration();
	static void MovePlayer();
	static void KeepPlayerOnScreen();

	//Enemies
	static void ManageEnemies();
	static void MoveEnemy(EnemyNS::Enemy& enemy);
	static void KeepEnemyOnScreen(EnemyNS::Enemy& enemy);
	static void RemoveInactiveEnemies();

	//Bullet
	static void ManageBullets();
	static void MoveBullet(BulletNS::Bullet& bullet);
	static void DeactivateBullet(BulletNS::Bullet& bullet);

	//Collisions
	static bool PlayerEnemyAreColliding(EnemyNS::Enemy& enemy);
	static bool BulletEnemeyAreColliding(BulletNS::Bullet& bullet, EnemyNS::Enemy& enemy);

	void Load()
	{
		PlayerNS::Load();
		EnemyNS::Load();
		background = LoadTexture("res/Backgrounds/GameplayBackground.png");
	}

	bool Update()
	{
		enemyRemovalCount += GetFrameTime();

		SetPlayerRotation();

		//Shoot
		if (IsMouseButtonPressed(0))
		{
			Shoot();			
		}

		//Move
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

		ManageBullets();

		return player.lives > 0;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		PlayerNS::Draw();
		EnemyNS::Draw();
	}

	void Unload()
	{
		UnloadTexture(player.sprite.texture);
		UnloadTexture(background);
	}


	//Player
	void SetPlayerRotation()
	{
		Vector2 mousePosition = GetMousePosition();
		Vector2 playerPosition = player.pos;

		rotationAngle = CalculateAngleBetweenPoints(playerPosition, mousePosition);

		player.sprite.rotation = rotationAngle;
	}

	void SetPlayerAcceleration()
	{
		Vector2 newVelocity = Utils::CalculateVelocityFromAngle(rotationAngle, player.acceleration * GetFrameTime());

		player.speed.x += newVelocity.x;
		player.speed.y += newVelocity.y;

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

		player.sprite.destination.x = player.pos.x;
		player.sprite.destination.y = player.pos.y;

		player.collisionShape.center = player.pos;
	}

	void KeepPlayerOnScreen()
	{
		float spriteWidth = static_cast <float> (player.sprite.texture.width) * player.sprite.scale / 2;
		float spriteHeight = static_cast <float> (player.sprite.texture.height) * player.sprite.scale / 2;

		//Check x axis
		if (player.pos.x - spriteWidth > GetScreenWidth())
			player.pos.x = -spriteWidth;
		else if (player.pos.x + spriteWidth < 0)
			player.pos.x = static_cast <float> (GetScreenWidth()) + spriteWidth;

		//Check y axis
		if (player.pos.y - spriteHeight > GetScreenHeight())
			player.pos.y = -spriteHeight;
		else if (player.pos.y + spriteHeight < 0)
			player.pos.y = static_cast <float>(GetScreenHeight()) + spriteHeight;

		player.sprite.destination.x = player.pos.x;
		player.sprite.destination.y = player.pos.y;
	}


	//Enemies
	void ManageEnemies()
	{
		//Movement and collision with player
		for (int i = 0; i < static_cast <int>(enemies.size()); i++)
		{
			if (enemies[i].isActive)
			{
				MoveEnemy(enemies[i]);
				KeepEnemyOnScreen(enemies[i]);

				if (PlayerEnemyAreColliding(enemies[i]))
				{
					player.lives--;
					enemies[i].isActive = false;
				}
			}
		}

		//Delete inactive enemies 
		if (enemyRemovalCount >= enemyRemovalTime)
		{
			RemoveInactiveEnemies();
			enemyRemovalCount = 0.0f;
		}
	}

	void MoveEnemy(EnemyNS::Enemy& enemy)
	{
		enemy.collisionShape.center.x += enemy.speed.x * GetFrameTime();
		enemy.collisionShape.center.y += enemy.speed.y * GetFrameTime();
		enemy.sprite.destination.x = enemy.collisionShape.center.x;
		enemy.sprite.destination.y = enemy.collisionShape.center.y;
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

	}

	void RemoveInactiveEnemies()
	{
		#ifdef _DEBUG
				cout << "Enemigos antes de la eliminacion: " << enemies.size() << endl;
		#endif // _DEBUG

		//Find 
		auto FirstInactiveEnemy = remove_if(enemies.begin(), enemies.end(),
			[](const EnemyNS::Enemy& enemy) { return !enemy.isActive; });
		
		for (auto it = FirstInactiveEnemy; it != enemies.end(); ++it)
		{
			UnloadTexture(it->sprite.texture); // Descarga la textura del enemigo inactivo
		}

		enemies.erase(FirstInactiveEnemy, enemies.end());
		
		#ifdef _DEBUG
				cout << "Enemigos post eliminacion: " << enemies.size() << endl;
		#endif // _DEBUG

	}

	//Bullets
	void ManageBullets()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (player.weapon.bullets[i].isActive)
			{
				MoveBullet(player.weapon.bullets[i]);
				DeactivateBullet(player.weapon.bullets[i]);

				for (int j = 0; j < static_cast <int>(enemies.size()); j++)
				{
					if (enemies[j].isActive)
					{
						if (BulletEnemeyAreColliding(player.weapon.bullets[i], enemies[j]))
						{
							player.weapon.bullets[i].isActive = false;
							enemies[j].isActive = false;
							DivideEnemy(enemies[j]);

							break;
						}
					}
				}

			}
		}
	}

	void MoveBullet(BulletNS::Bullet& bullet)
	{
		bullet.shape.center.x += bullet.speed.x * GetFrameTime();
		bullet.shape.center.y += bullet.speed.y * GetFrameTime();
	}

	void DeactivateBullet(BulletNS::Bullet& bullet)
	{
		if (bullet.shape.center.x < 0 ||
			bullet.shape.center.x > GetScreenWidth() ||
			bullet.shape.center.y < 0 ||
			bullet.shape.center.y > GetScreenHeight())
		{
			bullet.isActive = false;
		}
	}


	//Collisions
	bool PlayerEnemyAreColliding(EnemyNS::Enemy& enemy)
	{
		float distX = player.collisionShape.center.x - enemy.collisionShape.center.x;
		float distY = player.collisionShape.center.y - enemy.collisionShape.center.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		return distance <= player.collisionShape.radius + enemy.collisionShape.radius;
	}

	bool BulletEnemeyAreColliding(BulletNS::Bullet& bullet, EnemyNS::Enemy& enemy)
	{
		float distX = bullet.shape.center.x - enemy.collisionShape.center.x;
		float distY = bullet.shape.center.y - enemy.collisionShape.center.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		return distance <= bullet.shape.radius + enemy.collisionShape.radius;
	}

}