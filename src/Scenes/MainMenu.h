#pragma once
#include "Button.h"

namespace Bton = Button;

namespace MainMenu
{
	void Load();
	void Draw();
	void Unload();

	extern Bton::Button play;
	extern Bton::Button tutorial;
	extern Bton::Button credits;
	extern Bton::Button exit;
}