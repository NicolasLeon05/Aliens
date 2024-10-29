#include "Game.h"

#include <iostream>

#include "raylib.h"

#include "Scene_MainMenu.h"
#include "Scene_Gameplay.h"
#include "Scene_Tutorial.h"
#include "Scene_Credits.h"
#include "Scene_Pause.h"
#include "Button.h"
#include "SoundManager.h"

using namespace Button;
using namespace SoundManager;

namespace Game
{
	static const int screenWidth = 1024;
	static const int screenHeight = 768;

	enum class CurrentScene
	{
		MainMenu, Gameplay, Tutorial, Credits, Pause, Results
	};

	static CurrentScene currentScene;

	static float gameShouldClose;
	static float gameplayOnGoing;

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

		gameShouldClose = false;
		gameplayOnGoing = false;

		currentScene = CurrentScene::MainMenu;

		InitWindow(screenWidth, screenHeight, "Aliens");

		SetExitKey(0);

		SoundManager::Load();
		music = menuMusic;

		MainMenu::Load();
		Gameplay::Load();
		Tutorial::Load();
		Credits::Load();
		Pause::Load();
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

				gameplayOnGoing = true;
				currentScene = CurrentScene::Gameplay;
			}
			else if (IsButtonPressed(MainMenu::tutorial))
			{
				currentScene = CurrentScene::Tutorial;
			}
			else if (IsButtonPressed(MainMenu::credits))
			{
				currentScene = CurrentScene::Credits;
			}
			else if (IsButtonPressed(MainMenu::exit))
			{
				gameShouldClose = true;
			}

			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			gameplayOnGoing = Gameplay::Update();

			if (IsButtonPressed(Gameplay::pause) || IsKeyReleased(KEY_ESCAPE))
				currentScene = CurrentScene::Pause;

			if (!gameplayOnGoing)
				ResetGame(); //Change for result screen

			break;
		}


		case Game::CurrentScene::Tutorial:
		{
			if (IsButtonPressed(Tutorial::returnToMenu))
				currentScene = CurrentScene::MainMenu;

			break;
		}


		case Game::CurrentScene::Credits:
		{
			Credits::Update();

			if (IsButtonPressed(Credits::returnToMenu))
			{
				currentScene = CurrentScene::MainMenu;
			}
			break;
		}


		case Game::CurrentScene::Pause:
		{
			if (IsButtonPressed(Pause::returnToMenu))
			{
				currentScene = CurrentScene::MainMenu;
			}
			else if (IsButtonPressed(Pause::continuePlaying) || IsKeyReleased(KEY_ESCAPE))
			{
				currentScene = CurrentScene::Gameplay;
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


		case Game::CurrentScene::Credits:
		{
			Credits::Draw();
			break;
		}

		case Game::CurrentScene::Pause:
		{
			Pause::Draw();
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
		Gameplay::Unload();
		SoundManager::Unload();
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