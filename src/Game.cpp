#include "Game.h"

#include <iostream>

#include "raylib.h"

#include "Scene_MainMenu.h"
#include "Scene_Gameplay.h"
#include "Scene_Tutorial.h"
#include "Button.h"
#include "SoundManager.h"

using namespace Button;
using namespace SoundManager;

namespace Game
{
	enum class CurrentScene
	{
		MainMenu, Gameplay, Tutorial
	};

	CurrentScene currentScene;

	const int screenWidth = 1024;
	const int screenHeight = 768;

	static float gameShouldClose = false;

	static Music music;

	static void Load();
	static void Update();
	static void Draw();
	static void Unload();

	static void ResetGame();

	void Run()
	{
		Load();
		PlayMusicStream(music);
		do
		{
			Update();
			Draw();

		} while (!gameShouldClose);

		Unload();
	}


	void Load()
	{
		srand(static_cast<unsigned int>(time(NULL)));

		currentScene = CurrentScene::MainMenu;
		InitWindow(screenWidth, screenHeight, "Aliens");

		SetExitKey(0);

		SoundManager::Load();
		music = menuMusic;

		MainMenu::Load();
		Tutorial::Load();
		Gameplay::Load();
	}


	void Update()
	{
		gameShouldClose = WindowShouldClose();

		switch (currentScene)
		{
		case Game::CurrentScene::MainMenu:
		{
			if (IsButtonPressed(MainMenu::play))
			{
				StopMusicStream(music);
				music = gameplayMusic;
				PlayMusicStream(music);
				currentScene = CurrentScene::Gameplay;
			}
			else if (IsButtonPressed(MainMenu::tutorial))
			{
				currentScene = CurrentScene::Tutorial;
			}
			else if (IsButtonPressed(MainMenu::exit))
			{
				gameShouldClose = true;
			}

			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			Gameplay::Update();


			if (IsKeyReleased(KEY_ESCAPE))
				ResetGame(); //Change for a pause screen
			break;
		}

		case Game::CurrentScene::Tutorial:
		{
			if (IsButtonPressed(Tutorial::exit))
			{
				currentScene = CurrentScene::MainMenu;
			}
			break;
		}

		default:
		{
			break;
		}
		}
		UpdateMusicStream(music);
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

		case Game::CurrentScene::Tutorial:
		{
			Tutorial::Draw();
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


	void Unload()
	{
		UnloadMusicStream(music);  // Descarga la m�sica
		Gameplay::Unload();
		CloseAudioDevice();
		CloseWindow();
	}


	void ResetGame()
	{
		currentScene = CurrentScene::MainMenu;

		StopMusicStream(music);  
		music = menuMusic;       
		PlayMusicStream(music);

		Gameplay::Load();
	}
}