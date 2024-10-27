#include "SoundManager.h"

namespace SoundManager
{	
	Music menuMusic;
	Music gameplayMusic;
	Sound accelerateSound;
	Sound shootSound;

	void Load()
	{
		InitAudioDevice();
		menuMusic = LoadMusicStream("res/Music/Pixel_StarsV2.mp3");
		gameplayMusic = LoadMusicStream("res/Music/Pixel_Stars.mp3");

		accelerateSound = LoadSound("res/SFX/Accelerate.mp3");
		SetSoundVolume(accelerateSound, 0.5);

		shootSound = LoadSound("res/SFX/Shoot.mp3");
		SetSoundVolume(shootSound, 0.5);
	}

	void Unload()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);

		UnloadSound(accelerateSound);
		UnloadSound(shootSound);

		CloseAudioDevice();
	}
}
