#include "Game.h"

#include "raylib.h"

#include "Scene_MainMenu.h"
#include "Scene_Gameplay.h"

#include "Button.h"

#include "SoundManager.h"

using namespace Button;
using namespace SoundManager;

namespace Game
{
	enum class CurrentScene
	{
		MainMenu, Gameplay
	};

	CurrentScene currentScene;

	const int screenWidth = 1024;
	const int screenHeight = 768;

	static Music music;

	static void Init();
	static void Update();
	static void Draw();
	static void Deinit();

	static void ResetGame();

	void Run()
	{
		Init();
		PlayMusicStream(music);
		do
		{
			Update();
			Draw();

		} while (!WindowShouldClose() || currentScene != CurrentScene::MainMenu);

		Deinit();
	}


	void Init()
	{
		currentScene = CurrentScene::MainMenu;
		InitWindow(screenWidth, screenHeight, "Aliens");
		SoundManager::Init();
		music = menuMusic;

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
			{
				StopMusicStream(music);
				music = gameplayMusic;
				PlayMusicStream(music);
				currentScene = CurrentScene::Gameplay;
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
		UnloadMusicStream(music);  // Descarga la música
		CloseAudioDevice();
		CloseWindow();
	}


	void ResetGame()
	{
		currentScene = CurrentScene::MainMenu;

		StopMusicStream(music);  
		music = menuMusic;       
		PlayMusicStream(music);

		Gameplay::Init();
	}
}