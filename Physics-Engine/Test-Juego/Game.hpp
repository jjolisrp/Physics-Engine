#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <SDL.h>

class Game
{
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	int count;
	int frameCount, timerFPS, lastFrame;

public:
	Game();

	void Loop();

	void Update();

	void Renderer();

	void Input();

	~Game();
};

#endif