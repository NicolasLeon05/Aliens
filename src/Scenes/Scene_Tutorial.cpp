#include "Scene_Tutorial.h"

namespace Tutorial
{
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

		exit = Bton::Create("Exit", screenCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		int titleFontSize = fontSize * 2;
		const char* HowToMove = "How to play";
		int textLength = MeasureText(HowToMove, titleFontSize);
		int textX = static_cast<int> (screenCenterX + textLength / 6);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(HowToMove, textX, textY, titleFontSize, RED);

		Bton::Draw(exit, fontSize);
	}
}