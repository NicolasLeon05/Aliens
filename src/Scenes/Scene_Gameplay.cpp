#include "Scene_Gameplay.h"

#include "raylib.h"
#include "Player.h"
#include "math.h"

namespace PlayerNS = Player;
using namespace PlayerNS;

#include <iostream>  //Para debug
using namespace std; //Para debug

namespace Gameplay
{
	static Vector2 mousePosition;
	static float r;
	static float angle;

	static float GetPlayerRotation();


	void Init()
	{
		PlayerNS::Init();
	}


	void Update()
	{
		
	}


	void Draw()
	{
		ClearBackground(BLACK);
		PlayerNS::Draw();
	}


	float GetPlayerRotation()
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
}