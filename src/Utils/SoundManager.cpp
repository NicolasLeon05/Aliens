#include "SoundManager.h"

namespace SoundManager
{	
	Music menuMusic;
	Music gameplayMusic;

	void Init()
	{
		InitAudioDevice();
		menuMusic = LoadMusicStream("res/Music/Asteroids_Adventure.wav");
		gameplayMusic = LoadMusicStream("res/Music/Pixel_Stars.wav");
	}
}
