#include "GameOver.h"

#include <iostream>
#include <string>

#include "Text.h"

using namespace std;

namespace GameOver
{
	static Texture2D background;

	static Text::Text gameOver;
	static Text::Text bestScore;
	static Text::Text currentScore;

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

		bestScore = Text::CreateText("Best score: ", regularFontSize, {screenCenterX, screenHeight / screenDivision * heightMultiplyer}, GREEN);
		Text::SetTextLength(bestScore);

		heightMultiplyer += 2;

		currentScore = Text::CreateText("Score: ", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
		Text::SetTextLength(currentScore);


		returnToMenu = Bton::Create("Menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
		playAgain = Bton::Create("Play Again", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}

	void Draw()
	{
		ClearBackground(BLACK);

		DrawTexture(background, 0, 0, WHITE);

		Text::DrawCentered(gameOver);
		Text::DrawCentered(bestScore);
		Text::DrawCentered(currentScore);

		Bton::Draw(returnToMenu, buttonFontSize);
		Bton::Draw(playAgain, buttonFontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}

	void SetScores(int maxScore, int runScore)
	{
		string bestScoreString = "Best score: " + to_string(maxScore);
		string currentScoreString = "Score: " + to_string(runScore);

		bestScore.content = bestScoreString;
		bestScore.length = MeasureText(bestScore.content.c_str(), bestScore.fontSize);

		currentScore.content = currentScoreString;
		currentScore.length = MeasureText(currentScore.content.c_str(), currentScore.fontSize);
	}
}