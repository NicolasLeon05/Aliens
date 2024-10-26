#include "Bullet.h"

namespace Bullet
{
	void Load(Bullet& bullet)
	{
		bullet.isActive = false;
		bullet.speed = { 0,0 };

		bullet.shape.center = { 0,0 };
		bullet.shape.radius = 5;

		bullet.color = GREEN;
	}

	void Draw(Bullet bullet)
	{
		DrawCircle(static_cast <int> (bullet.shape.center.x),
			static_cast <int> (bullet.shape.center.y),
			bullet.shape.radius,
			bullet.color);

	}
}