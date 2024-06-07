#include "Game.hpp"

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGH = 720;

Game::Game()
{
	SDL_Init(0);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGH, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "First Game");

	running = true;
	count = 0;

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
			frameCount = 0;
			count++;
		}

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

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}