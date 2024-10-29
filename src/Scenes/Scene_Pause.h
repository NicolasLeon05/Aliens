#pragma once
#include "Button.h"

namespace Bton = Button;

namespace Pause
{
	extern Bton::Button menu;
	extern Bton::Button continuePlaying;

	void Load();
	void Draw();
}