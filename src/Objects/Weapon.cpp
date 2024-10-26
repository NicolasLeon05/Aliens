#include "Weapon.h"

namespace Weapon
{

	void Load(Weapon& weapon)
	{
		weapon.bulletSpeed = 500;

		for (int i = 0; i < maxBullets; i++)
		{
			BulletNS::Load(weapon.bullets[i]);
		}
	}

	void DrawBullets(Weapon weapon)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (weapon.bullets[i].isActive)
				BulletNS::Draw(weapon.bullets[i]);
		}
	}
}