#include "Scene_MainMenu.h"

#include "raylib.h"


namespace Bton = Button;

namespace MainMenu
{
	Bton::Button play;

	void Init()
	{
		float width = 250;
		float height = 70;
		play = Bton::Create("Play", static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2), width, height);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		DrawText("Menu", static_cast<int>(play.rec.x), static_cast<int>(play.rec.y), 40, RED);
		Bton::Draw(play);
	}

}