#include "Scene_Tutorial.h"

namespace Tutorial
{
	static Texture2D background;

	Bton::Button returnToMenu;

	static int fontSize = 40;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	void Load()
	{
		background = LoadTexture("res/Backgrounds/MenuBackground.png");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Bton::Create("Return", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		int titleFontSize = fontSize * 2;
		const char* HowToPlay = "How to play";
		int textLength = MeasureText(HowToPlay, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize);
		DrawText(HowToPlay, textX, textY, titleFontSize, RED);

		Bton::Draw(returnToMenu, fontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}
}