#include "Player.h"

namespace Player
{
	Player player;

	void Init()
	{
		player.sprite = LoadTexture("res/SpaceShip.png");
		player.scale = 1;
		player.x = 512;
		player.y = 374;
	}

	void Draw(float rotation)
	{
		DrawTextureEx(player.sprite, Vector2{player.x, player.y}, rotation, player.scale, WHITE);
	}
}

