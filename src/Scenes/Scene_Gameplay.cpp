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

	void Init()
	{
		PlayerNS::Init();
	}


	void Update()
	{
		//Get polar coordinates of the mouse
		mousePosition = {  GetMousePosition().x - player.pos.x, player.pos.y - GetMousePosition().y };
		//cout << "x: " << mousePosition.x << " y: " << mousePosition.y << endl;
		
		r = static_cast<float> (sqrt(pow(mousePosition.x, 2) + pow(mousePosition.y, 2)));
		angle = atan(mousePosition.y / mousePosition.x);
		//Convert to degrees
		angle *= (180 / PI);

		if (mousePosition.x < 0)
			angle += 180.0f;
		else if (mousePosition.y < 0)
			angle += 360.0f;

		cout << angle << endl << endl;

		player.rotation = -angle+90;
	}


	void Draw()
	{
		ClearBackground(BLACK);
		PlayerNS::Draw();
	}
}