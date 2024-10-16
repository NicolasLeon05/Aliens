#include "Player.h"

namespace Player
{
	Player player;

	void Init()
	{
		player.sprite = LoadTexture("res/SpaceShip.png");
		player.rec.x = 512 - (player.rec.width / 2);
		player.rec.y = 384 - (player.rec.height / 2);
		player.rec.width = 50;
		player.rec.height = 50;

		player.color = RED;
	}

	void Draw()
	{
		DrawTextureEx(player.sprite, Vector2{ static_cast<float>(player.rec.x), static_cast<float>(player.rec.y)}, 0.0f, 0.3f, WHITE);
	}
}

