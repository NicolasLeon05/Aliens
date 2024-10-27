#pragma once
#include "raylib.h"

namespace SoundManager
{
	extern Music menuMusic;
	extern Music gameplayMusic;

	extern Sound accelerateSound;
	extern Sound shootSound;
	
	void Load();
	void Unload();

}