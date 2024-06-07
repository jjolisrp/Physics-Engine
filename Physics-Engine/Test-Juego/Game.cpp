#include "Game.hpp"
#include <stdio.h>

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGH = 720;

Game::Game()
{
	SDL_Init(0);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGH, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "First Game");

	running = true;
	count = 0;

	object1.SetDest(100, 100, 315, 250);
	object1.SetSource(0, 0, 315, 250);
	object1.SetImage("Ratón.png", renderer);

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

		if (count > 3)
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

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}