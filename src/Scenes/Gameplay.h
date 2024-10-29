#pragma once
#include "Button.h"

namespace Bton = Button;

namespace Gameplay
{
	extern Bton::Button pause;

	void Load();
	bool Update();
	void Draw();
	void Unload();

	int GetRunScore();
}