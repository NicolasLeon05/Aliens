#pragma once
#include "Bullet.h"

namespace BulletNS = Bullet;
using namespace BulletNS;

namespace Weapon
{
	const int maxBullets = 40;

	struct Weapon
	{
		float cooldown;
		BulletNS::Bullet bullets[maxBullets];
	};

	void Load(Weapon weapon);

	void DrawBullets(Weapon weapon);
}

