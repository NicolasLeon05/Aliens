#pragma once

#include "raylib.h"

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
		Texture2D sprite;
		Rectangle source;
		Rectangle destination;
		Vector2 pos;
		float scale;
		float rotation;
		
		//Collision
		Circle::Circle collisionShape;

		//Movement
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

	void Shoot();
}
