#include "Player.h"

#include "cmath"

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	void Load()
	{
		player.lives = 5;

		//Sprite
		player.sprite = LoadTexture("res/Sprite/PlayerSpaceship.png");
		player.scale = 1.75f;
		player.source = { 0,
						  0,
						  static_cast<float>(player.sprite.width),
						  static_cast<float>(player.sprite.height)
		};

		player.pos.x = static_cast<float>(GetScreenWidth() / 2);
		player.pos.y = static_cast<float>(GetScreenHeight() / 2);

		float destinationWidth = player.sprite.width * player.scale;
		float destinationHeight = player.sprite.height * player.scale;

		player.destination = { player.pos.x,
							   player.pos.y,
							   destinationWidth,
							   destinationHeight
		};

		float spriteCenterX = player.sprite.width * player.scale / 2;
		float spriteCenterY = player.sprite.height * player.scale / 2;
		spriteCenter = { spriteCenterX, spriteCenterY };

		//Collision
		player.collisionShape.center = player.pos;
		player.collisionShape.radius = 30;

		//Speed
		player.maxAcceleration = 300.0f;
		player.acceleration = 0.2f;
		player.speed = { 0,0 };

		//Bullets
		WeaponNS::Load(player.weapon);
	}

	void Draw()
	{
		//Collision
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.collisionShape.center.x), static_cast <int>(player.collisionShape.center.y), player.collisionShape.radius, BLUE);
#endif // _DEBUG

		DrawBullets(player.weapon);

		DrawTexturePro(player.sprite,
			player.source,
			player.destination,
			spriteCenter,
			player.rotation,
			WHITE);



		//Center
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.pos.x), static_cast <int>(player.pos.y), 5, YELLOW);
#endif // _DEBUG
	}

	void Shoot()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!player.weapon.bullets[i].isActive)
			{
				player.weapon.bullets[i].shape.center = player.pos;

				float angleInRadians = (player.rotation) * (PI / 180.0f);
				player.weapon.bullets[i].speed = {
					cos(angleInRadians) * player.weapon.bulletSpeed,
					sin(angleInRadians) * player.weapon.bulletSpeed
				};

				player.weapon.bullets[i].isActive = true;
				break;
			}
		}
	}
}

