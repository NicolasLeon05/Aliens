#include "Scene_GameOver.h"

#include "Text.h"

namespace GameOver
{
	static Texture2D background;

	static Text::Text gameOver;
	static Text::Text currentScore;
	static Text::Text maxScore;

	Bton::Button returnToMenu;
	Bton::Button playAgain;

	static int regularFontSize = 40;
	static int titleFontSize = 70;
	static int buttonFontSize = 40;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 10;
	static int heightMultiplyer = 1;
	static int textSeparation = 8;

	void Load()
	{

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		heightMultiplyer = 1;

		background = LoadTexture("res/Backgrounds/GameplayBackground.png");

		gameOver = Text::CreateText("Game Over", titleFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
		Text::SetTextLength(gameOver);

		heightMultiplyer += 2;

		maxScore = Text::CreateText("Best score: ", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
		Text::SetTextLength(maxScore);

		heightMultiplyer += 2;

		currentScore = Text::CreateText("Score: ", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
		Text::SetTextLength(currentScore);


		returnToMenu = Bton::Create("Menu", screenCenterX - buttonWidth, screenHeight / 6 * 5, buttonWidth, buttonHeight);
		playAgain = Bton::Create("Play Again", screenCenterX + buttonWidth, screenHeight / 6 * 5, buttonWidth, buttonHeight);
	}

	void Draw()
	{
		ClearBackground(BLACK);

		DrawTexture(background, 0, 0, WHITE);

		Text::DrawCentered(gameOver);
		Text::DrawCentered(maxScore);
		Text::DrawCentered(currentScore);

		Bton::Draw(returnToMenu, buttonFontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}
}