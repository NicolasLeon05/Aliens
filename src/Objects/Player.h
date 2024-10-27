#pragma once

#include "raylib.h"

#include "Sprite.h"
#include "Circle.h"
#include "Weapon.h"

namespace WeaponNS = Weapon;
using namespace WeaponNS;

namespace Player
{
	struct Player
	{
		int lives;

		//Drawing
		Vector2 pos;
		Sprite::Sprite sprite;
		
		//Collision
		Circle::Circle collisionShape;

		//Speed
		Vector2 speed;
		float maxAcceleration;
		float acceleration;

		//Bullets
		WeaponNS::Weapon weapon;
		float timeBetweenShots;
	};

	extern Player player;

	void Load();
	void Draw();
	void Unload();

	void Shoot();
}
