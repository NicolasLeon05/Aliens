#pragma once
#include "Button.h"

namespace Bton = Button;

namespace Credits
{
	void Load();
	void Update();
	void Draw();

	extern Bton::Button returnToMenu;
}