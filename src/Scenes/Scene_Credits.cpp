#include "Scene_Credits.h"

namespace Credits
{
	Bton::Button returnToMenu;

	static int regularFontSize = 25;
	static int titleFontSize = 70;
	static int buttonFontSize = 40;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 15;
	static int textSeparation = 8;


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


		//Credits (Title)
		{
			const char* Developer = "Develpoed by: Nicolas Leon";
			int textLength = MeasureText(Developer, titleFontSize);

			int textX = static_cast<int> (screenCenterX - textLength / 2);
			int textY = static_cast<int> (screenHeight / 6 - titleFontSize);

			DrawText(Developer, textX, textY, titleFontSize, RED);
		}

		//Sprites
		{
			const char* spritesText = "Sprites by MattWalkden";
			const char* spritesUrl = "(mattwalkden.itch.io/lunar-battle-pack)";

			int spritesTextLength = MeasureText(spritesText, regularFontSize);
			int spritesUrlLength = MeasureText(spritesUrl, regularFontSize);
			int totalTextLength = spritesTextLength + spritesUrlLength + textSeparation;

			int textX = static_cast<int>(screenCenterX - totalTextLength / 2);
			int textY = static_cast<int>(screenHeight / screenDivision * 3);

			DrawText(spritesText, textX, textY, regularFontSize, ORANGE);
			DrawText(spritesUrl, textX + spritesTextLength + textSeparation, textY, regularFontSize, BLUE);
		}


		//Music
		{
			const char* musicText = "Music by SunoAI";
			const char* musicUrl = "(suno.com)";

			int musicTextLength = MeasureText(musicText, regularFontSize);
			int musicUrlLength = MeasureText(musicUrl, regularFontSize);
			int totalTextLength = musicTextLength + musicUrlLength + textSeparation;

			int textX = static_cast<int>(screenCenterX - totalTextLength / 2);
			int textY = static_cast<int>(screenHeight / screenDivision * 4);

			DrawText(musicText, textX, textY, regularFontSize, ORANGE);
			DrawText(musicUrl, textX + musicTextLength + textSeparation, textY, regularFontSize, BLUE);
		}


		//Shoot
		{
			const char* shootText = "Shoot sound by CHAKONG";
			const char* shootUrl = "(pixabay.com/es/sound-effects/laser-gun-shot-sound-future-sci-fi-lazer-wobble-chakongaudio-174883)";

			int shootTextLength = MeasureText(shootText, regularFontSize);
			int shootUrlLength = MeasureText(shootUrl, regularFontSize - textSeparation);

			int textX1 = static_cast<int>(screenCenterX - shootTextLength / 2);
			int textX2 = static_cast<int>(screenCenterX - shootUrlLength / 2);

			int textY = static_cast<int>(screenHeight / screenDivision * 5);
			int textY2 = textY + regularFontSize + textSeparation;

			// Dibujar ambos textos
			DrawText(shootText, textX1, textY, regularFontSize, ORANGE);
			DrawText(shootUrl, textX2, textY2, regularFontSize - textSeparation, BLUE);
		}


		//Accelerate
		{
			const char* accelerateText = "Accelerate sound by Pixabay";
			const char* accelerateUrl = "(pixabay.com/es/sound-effects/065110-seamless-rocket-booster-roar-amp-crackle-42487)";

			int accelerateTextLength = MeasureText(accelerateText, regularFontSize);
			int accelerateUrlLength = MeasureText(accelerateUrl, regularFontSize - textSeparation);

			int textX1 = static_cast<int>(screenCenterX - accelerateTextLength / 2);
			int textX2 = static_cast<int>(screenCenterX - accelerateUrlLength / 2);

			int textY = static_cast<int>(screenHeight / screenDivision * 6.5);
			int textY2 = textY + regularFontSize + textSeparation;

			DrawText(accelerateText, textX1, textY, regularFontSize, ORANGE);
			DrawText(accelerateUrl, textX2, textY2, regularFontSize - textSeparation, BLUE);
		}


		//DestroyEnemy
		{
			const char* destroyEnemyText = "Enemy destruction sound by Driken5482";
			const char* destroyEnemyUrl = "(pixabay.com/es/sound-effects/retro-explode-1-236678)";

			int destroyEnemyTextLength = MeasureText(destroyEnemyText, regularFontSize);
			int destroyEnemyUrlLength = MeasureText(destroyEnemyUrl, regularFontSize - textSeparation);

			int textX1 = static_cast<int>(screenCenterX - destroyEnemyTextLength / 2);
			int textX2 = static_cast<int>(screenCenterX - destroyEnemyUrlLength / 2);

			int textY = static_cast<int>(screenHeight / screenDivision * 8);
			int textY2 = textY + regularFontSize + textSeparation;

			DrawText(destroyEnemyText, textX1, textY, regularFontSize, ORANGE);
			DrawText(destroyEnemyUrl, textX2, textY2, regularFontSize - textSeparation, BLUE);
		}


		//Lose life
		{
			const char* loseLifeText = "Lose life sound by Driken5482";
			const char* loseLifeUrl = "(pixabay.com/es/sound-effects/retro-hurt-1-236672)";

			int loseLifeTextLength = MeasureText(loseLifeText, regularFontSize);
			int loseLifeUrlLength = MeasureText(loseLifeUrl, regularFontSize - textSeparation);

			int textX1 = static_cast<int>(screenCenterX - loseLifeTextLength / 2);
			int textX2 = static_cast<int>(screenCenterX - loseLifeUrlLength / 2);

			int textY = static_cast<int>(screenHeight / screenDivision * 9.5);
			int textY2 = textY + regularFontSize + textSeparation;

			DrawText(loseLifeText, textX1, textY, regularFontSize, ORANGE);
			DrawText(loseLifeUrl, textX2, textY2, regularFontSize - textSeparation, BLUE);
		}


		//Gain life
		{
			const char* gainLifeText = "Gain life sound by Driken5482";
			const char* gainLifeUrl = "(pixabay.com/es/sound-effects/coin-c-02-102844)";

			int gainLifeTextLength = MeasureText(gainLifeText, regularFontSize);
			int gainLifeUrlLength = MeasureText(gainLifeUrl, regularFontSize - textSeparation);

			int textX1 = static_cast<int>(screenCenterX - gainLifeTextLength / 2);
			int textX2 = static_cast<int>(screenCenterX - gainLifeUrlLength / 2);

			int textY = static_cast<int>(screenHeight / screenDivision * 11);
			int textY2 = textY + regularFontSize + textSeparation;

			DrawText(gainLifeText, textX1, textY, regularFontSize, ORANGE);
			DrawText(gainLifeUrl, textX2, textY2, regularFontSize - textSeparation, BLUE);
		}


		Bton::Draw(returnToMenu, buttonFontSize);
	}
}