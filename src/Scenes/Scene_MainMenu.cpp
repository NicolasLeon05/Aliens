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
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;

	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = GetScreenWidth() / 2 - buttonWidth / 2;

		play = Bton::Create("Play", screenCenterX, static_cast<float>(screenHeight / 6 * 2), buttonWidth, buttonHeight);
		tutorial = Bton::Create("Tutorial", screenCenterX, static_cast<float>(screenHeight / 6 * 3), buttonWidth, buttonHeight);
		credits = Bton::Create("Credits", screenCenterX, static_cast<float>(screenHeight / 6 * 4), buttonWidth, buttonHeight);
		exit = Bton::Create("Exit", screenCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		int titleFontSize = fontSize * 2;
		const char* title = "Name";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX + textLength / 6);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, RED);

		Bton::Draw(play, fontSize);
		Bton::Draw(tutorial, fontSize);
		Bton::Draw(credits, fontSize);
		Bton::Draw(exit, fontSize);
	}

}