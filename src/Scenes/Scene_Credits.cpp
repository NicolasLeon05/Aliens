#include "Scene_Credits.h"

#include "Text.h"

namespace Credits
{
	static Texture2D background;

	static int regularFontSize = 25;
	static int titleFontSize = 70;
	static int buttonFontSize = 40;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 20;
	static int heightMultiplyer = 1;
	static int textSeparation = 8;

	Bton::Button returnToMenu;

	static Text::Text developerText;
	static Text::Text spritesText;
	static Text::Text spritesUrlText;
	static Text::Text musicText;
	static Text::Text musicUrlText;
	static Text::Text shootText;
	static Text::Text shootUrlText;
	static Text::Text accelerateText;
	static Text::Text accelerateUrlText;
	static Text::Text destroyEnemyText;
	static Text::Text destroyEnemyUrlText;
	static Text::Text loseLifeText;
	static Text::Text loseLifeUrlText;
	static Text::Text gainLifeText;
	static Text::Text gainLifeUrlText;
	static Text::Text backgroundsText;
	static Text::Text backgroundsUrlText;

	static Bton::Button spritesUrlButton;
	static Bton::Button musicUrlButton;
	static Bton::Button shootUrlButton;
	static Bton::Button accelerateUrlButton;
	static Bton::Button destroyEnemyUrlButton;
	static Bton::Button loseLifeUrlButton;
	static Bton::Button gainLifeUrlButton;
	static Bton::Button backgroundsUrlButton;

	void Load()
	{
		background = LoadTexture("res/Backgrounds/MenuBackground.png");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;


		//Texts
		{
			developerText = Text::CreateText("Developed by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer - 10 }, GREEN);
			Text::SetTextLength(developerText);

			heightMultiplyer += 2;

			spritesText = Text::CreateText("Sprites by MattWalkden", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(spritesText);


			spritesUrlText = Text::CreateText("(mattwalkden.itch.io/lunar-battle-pack)", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(spritesUrlText);

			heightMultiplyer++;

			musicText = Text::CreateText("Music by SunoAI", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(musicText);


			musicUrlText = Text::CreateText("(suno.com)", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(musicUrlText);

			heightMultiplyer++;

			shootText = Text::CreateText("Shoot sound by CHAKONG", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(shootText);

			heightMultiplyer++;

			shootUrlText = Text::CreateText("(pixabay.com/es/sound-effects/laser-gun-shot-sound-future-sci-fi-lazer-wobble-chakongaudio-174883)", regularFontSize - textSeparation, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(shootUrlText);

			heightMultiplyer++;

			accelerateText = Text::CreateText("Accelerate sound by Pixabay", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(accelerateText);

			heightMultiplyer++;

			accelerateUrlText = Text::CreateText("(pixabay.com/es/sound-effects/065110-seamless-rocket-booster-roar-amp-crackle-42487)", regularFontSize - textSeparation, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(accelerateUrlText);

			heightMultiplyer++;

			destroyEnemyText = Text::CreateText("Enemy destruction sound by Driken5482", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(destroyEnemyText);

			heightMultiplyer++;

			destroyEnemyUrlText = Text::CreateText("(pixabay.com/es/sound-effects/retro-explode-1-236678)", regularFontSize - textSeparation, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(destroyEnemyUrlText);

			heightMultiplyer++;

			loseLifeText = Text::CreateText("Lose life sound by Driken5482", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(loseLifeText);

			heightMultiplyer++;

			loseLifeUrlText = Text::CreateText("(pixabay.com/es/sound-effects/retro-hurt-1-236672)", regularFontSize - textSeparation, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(loseLifeUrlText);

			heightMultiplyer++;

			gainLifeText = Text::CreateText("Gain life sound by Driken5482", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(gainLifeText);

			heightMultiplyer++;

			gainLifeUrlText = Text::CreateText("(pixabay.com/es/sound-effects/coin-c-02-102844)", regularFontSize - textSeparation, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(gainLifeUrlText);

			heightMultiplyer++;

			backgroundsText = Text::CreateText("Backgrounds by Leonardo AI", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(backgroundsText);


			backgroundsUrlText = Text::CreateText("(mattwalkden.itch.io/lunar-battle-pack)", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(backgroundsUrlText);
		}


		//Buttons
		{
			spritesUrlButton = Bton::Create("", spritesUrlText.pos.x, spritesUrlText.pos.y, static_cast<float>(spritesUrlText.length), static_cast<float>(regularFontSize));

			musicUrlButton = Bton::Create("", musicUrlText.pos.x, musicUrlText.pos.y, static_cast<float>(musicUrlText.length), static_cast<float>(regularFontSize));

			shootUrlButton = Bton::Create("", shootUrlText.pos.x, shootUrlText.pos.y, static_cast<float>(shootUrlText.length), static_cast<float>(regularFontSize));

			accelerateUrlButton = Bton::Create("", accelerateUrlText.pos.x, accelerateUrlText.pos.y, static_cast<float>(accelerateUrlText.length), static_cast<float>(regularFontSize));

			destroyEnemyUrlButton = Bton::Create("", destroyEnemyUrlText.pos.x, destroyEnemyUrlText.pos.y, static_cast<float>(destroyEnemyUrlText.length), static_cast<float>(regularFontSize));

			loseLifeUrlButton = Bton::Create("", loseLifeUrlText.pos.x, loseLifeUrlText.pos.y, static_cast<float>(loseLifeUrlText.length), static_cast<float>(regularFontSize));

			gainLifeUrlButton = Bton::Create("", gainLifeUrlText.pos.x, gainLifeUrlText.pos.y, static_cast<float>(gainLifeUrlText.length), static_cast<float>(regularFontSize));

			backgroundsUrlButton = Bton::Create("", backgroundsUrlText.pos.x, backgroundsUrlText.pos.y, static_cast<float>(backgroundsUrlText.length), static_cast<float>(regularFontSize));
		}



		returnToMenu = Bton::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);
	}

	void Update()
	{
		//Check clicks on links
		if (Bton::IsButtonPressed(spritesUrlButton)) OpenURL("https://mattwalkden.itch.io/lunar-battle-pack");
		if (Bton::IsButtonPressed(musicUrlButton)) OpenURL("https://suno.com");
		if (Bton::IsButtonPressed(shootUrlButton)) OpenURL("https://pixabay.com/es/sound-effects/laser-gun-shot-sound-future-sci-fi-lazer-wobble-chakongaudio-174883");
		if (Bton::IsButtonPressed(accelerateUrlButton)) OpenURL("https://pixabay.com/es/sound-effects/065110-seamless-rocket-booster-roar-amp-crackle-42487");
		if (Bton::IsButtonPressed(destroyEnemyUrlButton)) OpenURL("https://pixabay.com/es/sound-effects/retro-explode-1-236678");
		if (Bton::IsButtonPressed(loseLifeUrlButton)) OpenURL("https://pixabay.com/es/sound-effects/retro-hurt-1-236672");
		if (Bton::IsButtonPressed(gainLifeUrlButton)) OpenURL("https://pixabay.com/es/sound-effects/coin-c-02-102844");
		if (Bton::IsButtonPressed(backgroundsUrlButton)) OpenURL("https://mattwalkden.itch.io/lunar-battle-pack");
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);


		Text::DrawCentered(developerText);

		Text::DrawCentered(spritesText, spritesUrlText);

		Text::DrawCentered(musicText, musicUrlText);

		Text::DrawCentered(shootText);
		Text::DrawCentered(shootUrlText);

		Text::DrawCentered(accelerateText);
		Text::DrawCentered(accelerateUrlText);

		Text::DrawCentered(destroyEnemyText);
		Text::DrawCentered(destroyEnemyUrlText);

		Text::DrawCentered(loseLifeText);
		Text::DrawCentered(loseLifeUrlText);

		Text::DrawCentered(gainLifeText);
		Text::DrawCentered(gainLifeUrlText);

		Text::DrawCentered(backgroundsText, backgroundsUrlText);

		Bton::Draw(returnToMenu, buttonFontSize);
	}


	void Unload()
	{
		UnloadTexture(background);
	}
}