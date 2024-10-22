#include "SoundManager.h"

namespace SoundManager
{	
	Music menuMusic;
	Music gameplayMusic;
	Sound accelerateSound;

	void Init()
	{
		InitAudioDevice();
		menuMusic = LoadMusicStream("res/Music/Asteroids_Adventure.mp3");
		gameplayMusic = LoadMusicStream("res/Music/Pixel_Stars.mp3");

		accelerateSound = LoadSound("res/SFX/Accelerate.mp3");
		SetSoundVolume(accelerateSound, 0.5);

	}
}
