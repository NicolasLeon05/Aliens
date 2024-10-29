#include "Scene_Pause.h"

namespace Pause
{
	Bton::Button menu;
	Bton::Button continuePlaying;

	static int fontSize = 40;
	static int titleFontSize = fontSize * 2;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	void Load()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		menu = Bton::Create("Menu", buttonCenterX - buttonWidth / 2, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		continuePlaying = Bton::Create("Continue", buttonCenterX + buttonWidth / 2, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
	}

	void Draw()
	{
		ClearBackground(BLACK);

		const char* title = "Game Paused";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, RED);

		Bton::Draw(menu, fontSize);
		Bton::Draw(continuePlaying, fontSize);
	}
}