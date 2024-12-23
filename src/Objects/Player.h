#pragma once

#include "raylib.h"

#include "Objects/Sprite.h"
#include "Objects/Circle.h"
#include "Objects/Weapon.h"

namespace WeaponNS = Weapon;
using namespace WeaponNS;

namespace Player
{
	struct Player
	{
		int lives;
		int score;

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
