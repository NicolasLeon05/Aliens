#include "Player.h"

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	void Init()
	{
		player.sprite = LoadTexture("res/Sprite/SpaceShip.png");
		player.scale = 0.15f;
		player.source = { 0,0, static_cast<float>(player.sprite.width), static_cast<float>(player.sprite.height) };
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

		player.maxAcceleration = 400.0f;
		player.acceleration = 0.3f;
		player.speed = { 0,0 };
	}

	void Draw()
	{
		DrawTexturePro(player.sprite, player.source, player.destination, spriteCenter, player.rotation, WHITE);
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.pos.x), static_cast <int>(player.pos.y), 5, RED);
#endif // _DEBUG

	}
}

