#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <fstream>
#include <vector>
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
	//int count;
	Object object1;
	int mouseX, mouseY;
	Audio effect;
	Entity player;
	int idleR, idleL, walkR, walkL, shootR, shootL;
	vector<Object> map;
	int mapX, mapY;
	int scrollSpeed;
	bool l, r, u, d;
	float deltaTime, fps;
	Uint32 lastTime, fpsTimer;
	int frameCount;

public:
	Game();

	void Loop();

	void Update();

	void Renderer();

	void Input();

	void Draw(Object o);

	void DrawFonts(const char* message, int x, int y, int r, int g, int b);

	void LoadMap(const char* filename);

	void DrawMap();

	void Scroll(int x, int y);

	~Game();
};

#endif