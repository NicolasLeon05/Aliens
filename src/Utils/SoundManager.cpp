#include "SoundManager.h"

namespace SoundManager
{	
	Music menuMusic;
	Music gameplayMusic;

	Sound accelerateSound;
	Sound shootSound;
	Sound destroyEnemySound;
	Sound getHitSound;
	Sound getLifeSound;

	void Load()
	{
		InitAudioDevice();
		menuMusic = LoadMusicStream("res/Music/Pixel_StarsV2.mp3");
		gameplayMusic = LoadMusicStream("res/Music/Pixel_Stars.mp3");

		accelerateSound = LoadSound("res/SFX/Accelerate.mp3");
		SetSoundVolume(accelerateSound, 0.3f);

		shootSound = LoadSound("res/SFX/Shoot.mp3");
		SetSoundVolume(shootSound, 0.3f);

		destroyEnemySound = LoadSound("res/SFX/DestroyEnemy.mp3");
		SetSoundVolume(destroyEnemySound, 0.3f);

		getHitSound = LoadSound("res/SFX/GetHit.mp3");
		SetSoundVolume(getHitSound, 1.0f);
		
		getLifeSound = LoadSound("res/SFX/GetLife.mp3");
		SetSoundVolume(getLifeSound, 1.5f);
	}

	void Unload()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);

		UnloadSound(accelerateSound);
		UnloadSound(shootSound);
		UnloadSound(destroyEnemySound);
		UnloadSound(getHitSound);
		UnloadSound(getLifeSound);

		CloseAudioDevice();
	}
}
