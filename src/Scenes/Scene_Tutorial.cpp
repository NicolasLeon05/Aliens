#include "Scene_Tutorial.h"

namespace Tutorial
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

		exit = Bton::Create("Exit", screenCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		const char* gameName = "Name";
		int textLength = MeasureText(gameName, fontSize * 2);
		int textX = static_cast<int> (screenCenterX + textLength / 6);
		int textY = static_cast<int> (screenHeight / 6 - fontSize * 2 / 2);
		DrawText(gameName, textX, textY, fontSize * 2, RED);

		Bton::Draw(play, fontSize);
		Bton::Draw(tutorial, fontSize);
		Bton::Draw(credits, fontSize);
		Bton::Draw(exit, fontSize);
	}
}