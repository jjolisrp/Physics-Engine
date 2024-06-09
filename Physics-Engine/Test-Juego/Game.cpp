#include "Game.hpp"
#include <stdio.h>

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGH = 720;

Game::Game()
{
	SDL_Init(0);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGH, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "First Game");

	TTF_Init();

	running = true;
	count = 0;

	object1.SetDest(100, 100, 75, 75);
	object1.SetSource(0, 0, 75, 75);
	object1.SetImage("Raton.png", renderer);

	Loop();
}

void Game::Loop()
{
	while (running)
	{
		lastFrame = SDL_GetTicks();
		static int lastTime;
		if (lastFrame >= (lastTime + 1000))
		{
			lastTime = lastFrame;
			fps = frameCount;
			frameCount = 0;
			count++;
		}
		printf("fps: %d\n", fps);

		Renderer();
		Input();
		Update();

		//Finaliza el programa en funcion de los bubcles
		if (count > 5)
		{
			running = false;
		}
	}
}

void Game::Update()
{

}

void Game::Renderer()
{
	SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGH;
	SDL_RenderFillRect(renderer, &rect);

	Draw(object1);
	DrawFonts("GAMEPLAY", 20, 30, 0, 0, 0, 24);

	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	SDL_RenderPresent(renderer);
}

void Game::Input()
{

}

void Game::Draw(Object o)
{
	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopy(renderer, o.getTexture(), &src, &dest);
}

void Game::DrawFonts(const char* message, int x, int y, int r, int g, int b, int size)
{
	SDL_Surface* surface;
	SDL_Texture* texture;

	TTF_Font* font = TTF_OpenFont("Sixty.ttf", size);

	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 255;

	SDL_Rect rect;
	surface = TTF_RenderText_Solid(font, message, color);

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	rect.x = x;
	rect.y = y;
	rect.w = surface->w;
	rect.h = surface->h;

	SDL_FreeSurface(surface);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}

Game::~Game()
{
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}