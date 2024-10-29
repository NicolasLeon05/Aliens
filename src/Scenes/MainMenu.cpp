#include "MainMenu.h"

#include "raylib.h"

namespace Bton = Button;

namespace MainMenu
{
	static Texture2D background;

	Bton::Button play;
	Bton::Button tutorial;
	Bton::Button credits;
	Bton::Button exit;

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

		play = Bton::Create("Play", buttonCenterX, static_cast<float>(screenHeight / 6 * 2), buttonWidth, buttonHeight);
		tutorial = Bton::Create("Tutorial", buttonCenterX, static_cast<float>(screenHeight / 6 * 3), buttonWidth, buttonHeight);
		credits = Bton::Create("Credits", buttonCenterX, static_cast<float>(screenHeight / 6 * 4), buttonWidth, buttonHeight);
		exit = Bton::Create("Exit", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		DrawTexture(background, 0, 0, WHITE);

		int titleFontSize = fontSize * 2;
		const char* title = "Aliens";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, GREEN);

		Bton::Draw(play, fontSize);
		Bton::Draw(tutorial, fontSize);
		Bton::Draw(credits, fontSize);
		Bton::Draw(exit, fontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}

}