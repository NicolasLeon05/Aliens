#include "Game.h"
#include "raylib.h"

namespace Game
{
	const int screenWidth = 1024;
	const int screenHeight = 768;

	void Init();
	void Update();
	void Draw();
	void Deinit();

	void Run()
	{
		Init();

		do
		{
			Update();
			Draw();

		} while (!WindowShouldClose());

		Deinit();
	}


	void Init()
	{
		InitWindow(screenWidth, screenHeight, "Aliens");
	}


	void Update()
	{

	}


	void Draw()
	{
		BeginDrawing();

		DrawCircle(screenWidth / 2, screenHeight / 2, 30, RED);

		EndDrawing();
	}


	void Deinit()
	{
		CloseWindow();
	}
}