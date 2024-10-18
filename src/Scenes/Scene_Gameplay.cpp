#include "Scene_Gameplay.h"

#include "raylib.h"
#include "Player.h"
#include "math.h"

namespace PlayerNS = Player;
using namespace PlayerNS;

#ifdef _DEBUG
#include <iostream>
using namespace std;
#endif // DEBUG


namespace Gameplay
{
	static Vector2 mousePosition;
	static float r;
	static float angle;

	static void SetPlayerRotation();
	static void SetPlayerAcceleration();
	static void MovePlayer();
	static void KeepPlayerOnScreen();



	void Init()
	{
		PlayerNS::Init();
	}


	void Update()
	{
		SetPlayerRotation();
		if (IsMouseButtonDown(0))
		{
			SetPlayerAcceleration();
		}
		MovePlayer();
		KeepPlayerOnScreen();
	}


	void Draw()
	{
		ClearBackground(BLACK);
		PlayerNS::Draw();
	}


	void SetPlayerRotation()
	{
		//Get polar coordinates of the mouse
		mousePosition = { GetMousePosition().x - player.pos.x, player.pos.y - GetMousePosition().y };

		//Get angle in radians
		angle = atan(mousePosition.y / mousePosition.x);

		//Convert to degrees
		angle *= (180 / PI);

		//Check cuadrant variants
		if (mousePosition.x < 0)
			angle += 180.0f;
		else if (mousePosition.y < 0)
			angle += 360.0f;

		//Assing player rotation
		player.rotation = -angle + 90;
	}


	void SetPlayerAcceleration()
	{
		float angleInRadians = angle * (PI / 180);

		player.speed.x += player.acceleration * cos(angleInRadians);
		player.speed.y += (-player.acceleration) * sin(angleInRadians);

		float speedMagnitude = static_cast <float> (sqrt(pow(player.speed.x, 2) + pow(player.speed.y, 2)));
		if (speedMagnitude > player.maxAcceleration) {
			player.speed.x *= (player.maxAcceleration / speedMagnitude);
			player.speed.y *= (player.maxAcceleration / speedMagnitude);
		}
	}


	void MovePlayer()
	{
#ifdef _DEBUG
		//cout << "speed x: " << player.speed.x << " speed y: " << player.speed.y << endl << endl;
#endif // _DEBUG

		player.pos.x += player.speed.x * GetFrameTime();
		player.pos.y += player.speed.y * GetFrameTime();

		player.destination.x = player.pos.x;
		player.destination.y = player.pos.y;
	}


	void KeepPlayerOnScreen()
	{
		float spriteWidth = static_cast <float> (player.sprite.width) * player.scale / 2;
		float spriteHeight = static_cast <float> (player.sprite.height) * player.scale / 2;

		//Check x axis
		if (player.pos.x - spriteWidth > GetScreenWidth())
			player.pos.x = 0 - spriteWidth;
		else if (player.pos.x + spriteWidth < 0)
			player.pos.x = static_cast <float> (GetScreenWidth()) + spriteWidth;

		//Check y axis
		if (player.pos.y - spriteHeight > GetScreenHeight())
			player.pos.y = 0 - spriteHeight;
		else if (player.pos.y + spriteHeight < 0)
			player.pos.y = static_cast <float>(GetScreenHeight()) + spriteHeight;

		player.destination.x = player.pos.x;
		player.destination.y = player.pos.y;
	}

}