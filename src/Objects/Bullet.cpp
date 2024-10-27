#include "Bullet.h"

namespace Bullet
{
	void Load(Bullet& bullet)
	{
		//Sprite
		bullet.sprite.texture = LoadTexture("res/Sprite/Bullet.png");

		bullet.sprite.scale = 1.0f;

		bullet.sprite.source =
		{
			0,
			0,
			static_cast<float>(bullet.sprite.texture.width),
			static_cast<float>(bullet.sprite.texture.height)
		};

		float destinationWidth = bullet.sprite.texture.width * bullet.sprite.scale;
		float destinationHeight = bullet.sprite.texture.height * bullet.sprite.scale;

		bullet.sprite.destination =
		{
			bullet.collisionShape.center.x,
			bullet.collisionShape.center.y,
			destinationWidth,
			destinationHeight
		};

		bullet.isActive = false;
		bullet.speed = { 0,0 };

		bullet.collisionShape.center = { 0,0 };
		bullet.collisionShape.radius = 5;

		bullet.color = GREEN;
	}

	void Draw(Bullet bullet)
	{

#ifdef _DEBUG
		//Draw CollisionShape
		int x = static_cast<int> (bullet.collisionShape.center.x);
		int y = static_cast<int> (bullet.collisionShape.center.y);
		float radius = bullet.collisionShape.radius;

		DrawCircle(x, y, radius, RED);
#endif // _DEBUG

		//Draw sprite
		Vector2 spriteCenter =
		{
			bullet.sprite.texture.width * bullet.sprite.scale / 2,
			bullet.sprite.texture.height * bullet.sprite.scale / 2
		};

		DrawTexturePro(bullet.sprite.texture,
			bullet.sprite.source,
			bullet.sprite.destination,
			spriteCenter,
			bullet.sprite.rotation,
			WHITE);

	}
}