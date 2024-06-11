#ifndef __AUDIO_HPP__
#define __AUDIO_HPP__

#include <SDL.h>
#include <iostream>

class Audio
{
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceID;

public:
	Audio();

	void Load(const char* filename);

	void Play();

	~Audio();
};

#endif