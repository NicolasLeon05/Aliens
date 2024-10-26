#pragma once
#include "Bullet.h"

namespace BulletNS = Bullet;
using namespace BulletNS;

namespace Weapon
{
	const int maxBullets = 40;

	struct Weapon
	{
		int bulletSpeed;
		BulletNS::Bullet bullets[maxBullets];
	};

	void Load(Weapon& weapon);

	void DrawBullets(Weapon weapon);
}

