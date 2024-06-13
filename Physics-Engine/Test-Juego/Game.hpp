#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
using namespace std;
#include "Object.hpp"
#include "Audio.hpp"
#include "Entity.hpp"

class Game
{
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	TTF_Font* font;
	bool running;
	int count;
	int frameCount, timerFPS, lastFrame, fps;
	Object object1;
	int mouseX, mouseY;
	Audio effect;
	Entity player;
	int idle, shoot;


public:
	Game();

	void Loop();

	void Update();

	void Renderer();

	void Input();

	void Draw(Object o);

	void DrawFonts(const char* message, int x, int y, int r, int g, int b);

	~Game();
};

#endif