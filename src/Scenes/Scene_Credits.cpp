#include "Scene_Credits.h"

namespace Credits
{
	Bton::Button returnToMenu;

	static int fontSize = 40;
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

		returnToMenu = Bton::Create("Return", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		int titleFontSize = fontSize * 2;
		const char* Credits = "Credits";
		int textLength = MeasureText(Credits, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize);
		DrawText(Credits, textX, textY, titleFontSize, RED);

		Bton::Draw(returnToMenu, fontSize);
	}
}