#pragma once
#include "Interface/Button.h"

namespace Bton = Button;

namespace Tutorial
{
	void Load();
	void Draw();
	void Unload();

	extern Bton::Button returnToMenu;
}