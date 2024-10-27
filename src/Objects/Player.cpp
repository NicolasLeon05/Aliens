#include "Player.h"

#include "cmath"

#include "Utils.h"

using namespace Utils;

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	void Load()
	{
		player.lives = 5;

		//Sprite
		player.sprite.texture = LoadTexture("res/Sprite/PlayerSpaceship.png");
		player.sprite.scale = 1.75f;
		player.sprite.source =
		{
			0,
			0,
			static_cast<float>(player.sprite.texture.width),
			static_cast<float>(player.sprite.texture.height)
		};

		player.pos.x = static_cast<float>(GetScreenWidth() / 2);
		player.pos.y = static_cast<float>(GetScreenHeight() / 2);

		float destinationWidth = player.sprite.texture.width * player.sprite.scale;
		float destinationHeight = player.sprite.texture.height * player.sprite.scale;

		player.sprite.destination = 
		{
			player.pos.x,
			player.pos.y,
			destinationWidth,
			destinationHeight
		};

		float spriteCenterX = player.sprite.texture.width * player.sprite.scale / 2;
		float spriteCenterY = player.sprite.texture.height * player.sprite.scale / 2;
		spriteCenter = { spriteCenterX, spriteCenterY };

		//Collision
		player.collisionShape.center = player.pos;
		player.collisionShape.radius = 30;

		//Speed
		player.maxAcceleration = 1000.0f;
		player.acceleration = 200.0f;
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

		DrawTexturePro(
			player.sprite.texture,
			player.sprite.source,
			player.sprite.destination,
			spriteCenter,
			player.sprite.rotation,
			WHITE
		);

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

				player.weapon.bullets[i].speed = CalculateVelocityFromAngle(player.sprite.rotation, player.weapon.bulletSpeed);

				player.weapon.bullets[i].isActive = true;
				break;
			}
		}
	}
}

