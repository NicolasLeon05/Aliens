#include "Weapon.h"

namespace Weapon
{

	void Load(Weapon weapon)
	{
		weapon.cooldown = 0.5f;
		for (int i = 0; i < maxBullets; i++)
		{
			BulletNS::Load(weapon.bullets[i]);
		}
	}

	void DrawBullets(Weapon weapon)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			BulletNS::Draw(weapon.bullets[i]);
		}
	}
}