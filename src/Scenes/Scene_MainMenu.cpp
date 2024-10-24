#include "Scene_MainMenu.h"

#include "raylib.h"


namespace Bton = Button;

namespace MainMenu
{
	Bton::Button play;
	Bton::Button tutorial;
	Bton::Button credits;
	Bton::Button exit;

	static int fontSize = 40;
	static float width = 250;
	static float height = 70;
	static float screenHeight;
	static float centerX;

	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		centerX = GetScreenWidth() / 2 - width / 2;

		play = Bton::Create("Play", centerX, static_cast<float>(screenHeight / 6 * 2), width, height);
		tutorial = Bton::Create("Tutorial", centerX, static_cast<float>(screenHeight / 6 * 3), width, height);
		credits = Bton::Create("Credits", centerX, static_cast<float>(screenHeight / 6 * 4), width, height);
		exit = Bton::Create("Exit", centerX, static_cast<float>(screenHeight / 6 * 5), width, height);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		const char* gameName = "Name";
		int textLength = MeasureText(gameName, fontSize * 2);
		int textX = static_cast<int> (centerX + textLength / 6);
		int textY = static_cast<int> (screenHeight / 6 - fontSize * 2 / 2);
		DrawText(gameName, textX, textY, fontSize * 2, RED);

		Bton::Draw(play, fontSize);
		Bton::Draw(tutorial, fontSize);
		Bton::Draw(credits, fontSize);
		Bton::Draw(exit, fontSize);
	}

}