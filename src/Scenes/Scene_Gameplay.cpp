#include "Scene_Gameplay.h"

#include "raylib.h"
#include "Player.h"

namespace PlayerNS = Player;
using namespace PlayerNS;

#include <iostream>  //Para debug
using namespace std; //Para debug

namespace Gameplay
{
	static float playerRotation = 0.0f;


	void Init()
	{
		PlayerNS::Init();
	}


	void Update()
	{

	}


	void Draw()
	{
		PlayerNS::Draw(playerRotation);
		cout << "aaaa" << endl;
	}
}