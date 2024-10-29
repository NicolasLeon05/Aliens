#include "Scene_Tutorial.h"

#include "Text.h"

namespace Tutorial
{
	static Texture2D background;

	static Text::Text howToPlayText;
	static Text::Text moveText;
	static Text::Text shootText;
	static Text::Text scorePositionText;
	static Text::Text lifePositionText;
	static Text::Text getLifeText;
	static Text::Text gameplayText;

	Bton::Button returnToMenu;

	static int buttonFontSize = 40;
	static int regularFontSize = 30;
	static int titleFontSize = 70;

	static float buttonWidth = 250;
	static float buttonHeight = 70;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 12;
	static int heightMultiplier = 1;

	void Load()
	{
		heightMultiplier = 1;

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		howToPlayText = Text::CreateText("How to Play", titleFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, GREEN);
		Text::SetTextLength(howToPlayText);

		heightMultiplier+=2;

		moveText = Text::CreateText("Move with right click", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(moveText);

		heightMultiplier++;

		shootText = Text::CreateText("Shoot with left click", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(shootText);

		heightMultiplier++;

		scorePositionText = Text::CreateText("Your score will be on the top center of your screen", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(scorePositionText);

		heightMultiplier++;

		lifePositionText = Text::CreateText("Your lives will be on the top left of your screen", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(lifePositionText);

		heightMultiplier++;

		getLifeText = Text::CreateText("Every 5000 score you get 1 life", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(getLifeText);

		heightMultiplier++;

		gameplayText = Text::CreateText("Survive as long as you can!", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplier }, ORANGE);
		Text::SetTextLength(gameplayText);

		background = LoadTexture("res/Backgrounds/MenuBackground.png");


		returnToMenu = Bton::Create("Return", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		Text::DrawCentered(howToPlayText);
		Text::DrawCentered(moveText);
		Text::DrawCentered(shootText);
		Text::DrawCentered(scorePositionText);
		Text::DrawCentered(lifePositionText);
		Text::DrawCentered(getLifeText);
		Text::DrawCentered(gameplayText);

		Bton::Draw(returnToMenu, buttonFontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}
}