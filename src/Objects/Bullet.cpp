#include "Bullet.h"

namespace Bullet
{
	Bullet bullets[maxBullets];

	void Load()
	{
		float bulletSize = 5;

		for (int i = 0; i < maxBullets; i++)
		{
			bullets[i].isActive = false;
			bullets[i].speed = { 0,0 };
			bullets[i].shape.center = { 0,0 };
			bullets[i].shape.radius = bulletSize;
			bullets[i].color = GREEN;
		}
	}

	void Update()
	{

	}

	void Draw()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive)
			{
				DrawCircle(static_cast <int> (bullets[i].shape.center.x),
						   static_cast <int> (bullets[i].shape.center.y),
						   bullets[i].shape.radius,
						   bullets[i].color);
			}
		}
	}
}