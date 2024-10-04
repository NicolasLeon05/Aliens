#include "Game.h"
#include "raylib.h"

namespace Game
{
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

		} while (true);

		Deinit();
	}


	void Init()
	{

	}


	void Update()
	{

	}


	void Draw()
	{

	}


	void Deinit()
	{

	}
}