#pragma once
#include "Interface/Button.h"

namespace Bton = Button;

namespace Pause
{
	extern Bton::Button returnToMenu;
	extern Bton::Button continuePlaying;

	void Load();
	void Draw();
}