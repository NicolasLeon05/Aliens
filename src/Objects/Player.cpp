#include "Player.h"

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	void Init()
	{
		player.sprite = LoadTexture("res/SpaceShip.png");
		player.scale = 0.15f;
		player.source = { 0,0, static_cast<float>(player.sprite.width), static_cast<float>(player.sprite.height) };
		player.pos.x = static_cast<float>(GetScreenWidth() / 2);
		player.pos.y = static_cast<float>(GetScreenHeight() / 2);

		player.destination = { player.pos.x, player.pos.y, static_cast<float>(player.sprite.width * player.scale), static_cast<float>(player.sprite.height * player.scale) };
		spriteCenter = { static_cast<float>(player.sprite.width * player.scale) / 2, static_cast<float>(player.sprite.height * player.scale) / 2 };

	}

	void Draw()
	{
		DrawTexturePro(player.sprite, player.source, player.destination, spriteCenter, player.rotation, WHITE);
	}
}

