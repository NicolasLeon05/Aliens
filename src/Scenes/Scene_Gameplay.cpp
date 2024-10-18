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

	void SetPlayerRotation();

	void MovePlayer();



	void Init()
	{
		PlayerNS::Init();
	}


	void Update()
	{
		SetPlayerRotation();
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


	void MovePlayer()
	{

	}
}