#include "Scene_MainMenu.h"

#include "raylib.h"

namespace MainMenu
{
	void Draw()
	{
		ClearBackground(BLACK);
		DrawText("Menu", GetScreenHeight() / 2, 40, 40, RED);
	}
}