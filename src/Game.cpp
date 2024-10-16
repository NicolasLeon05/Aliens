#include "Game.h"

#include "raylib.h"

#include "Scene_MainMenu.h"
#include "Scene_Gameplay.h"

#include "Button.h"

using namespace Button;

namespace Game
{
	enum class CurrentScene
	{
		MainMenu, Gameplay
	};

	CurrentScene currentScene;

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
		currentScene = CurrentScene::MainMenu;
		InitWindow(screenWidth, screenHeight, "Aliens");

		MainMenu::Init();
		Gameplay::Init();
	}


	void Update()
	{
		switch (currentScene)
		{
		case Game::CurrentScene::MainMenu:
		{
			if (IsButtonPressed(MainMenu::play))
				currentScene = CurrentScene::Gameplay;

			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			Gameplay::Update();

			if (IsKeyReleased(KEY_SPACE))
				currentScene = CurrentScene::MainMenu;
			break;
		}


		default:
		{
			break;
		}
		}
	}


	void Draw()
	{
		BeginDrawing();

		switch (currentScene)
		{
		case Game::CurrentScene::MainMenu:
		{
			MainMenu::Draw();
			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			Gameplay::Draw();
			break;
		}


		default:
		{
			DrawCircle(screenWidth / 2, screenHeight / 2, 30, RED);
			break;
		}
		}

		EndDrawing();
	}


	void Deinit()
	{
		CloseWindow();
	}
}