#pragma once
#include "Button.h"

namespace Bton = Button;

namespace GameOver
{
	extern Bton::Button returnToMenu;
	extern Bton::Button playAgain;

	void Load();
	void Draw();
	void Unload();

	void SetScores(int maxScore, int runScore);
}