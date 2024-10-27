#pragma once
#include "raylib.h"

namespace SoundManager
{
	extern Music menuMusic;
	extern Music gameplayMusic;

	extern Sound accelerateSound;
	extern Sound shootSound;
	extern Sound destroyEnemySound;
	extern Sound getHitSound;
	extern Sound getLifeSound;
	
	void Load();
	void Unload();

}