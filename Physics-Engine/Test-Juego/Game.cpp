#include "Game.hpp"
#include <stdio.h>

int SCREEN_WIDTH = 1080;
int SCREEN_HEIGH = 720;

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGH, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "First Game");

	TTF_Init();

	running = true;
	count = 0;

	object1.SetDest(100, 100, 75, 75);
	object1.SetSource(0, 0, 75, 75);
	object1.SetImage("Raton.png", renderer);

	font = TTF_OpenFont("Sixty.ttf", 24);

	effect.Load("Retro.wav");
	effect.Play();

	player.SetImage("Player.png", renderer);
	player.SetDest(100, 100, 47*3, 45*3);
	idle = player.CreateCycle(1, 96, 90, 5, 20);
	shootR = player.CreateCycle(6, 96, 95, 5, 10);
	shootL = player.CreateCycle(5, 96, 95, 5, 10);
	player.SetCurrentAnimation(idle);

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
			//count++;
		}
		
		//printf("fps: %d\n", fps);
		//printf("MouseX: %d MouseY: %d\n", mouseX, mouseY);

		Renderer();
		Input();
		Update();

		//Finaliza el programa en funcion de los bubcles
		/*if (count > 5)
		{
			running = false;
		}*/
	}
}

void Game::Update()
{
	player.UpdateAnimation();
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
	DrawFonts("GAMEPLAY", 20, 30, 0, 0, 0);
	Draw(player);

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
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		//EVENTOS DE TECLADO
		if (e.type == SDL_QUIT)
		{
			running = false;
			cout << "Quitting" << endl;
		}

		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				running = false;
			}

			if (e.key.keysym.sym == SDLK_w)
			{
				
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				player.SetCurrentAnimation(shootL);
				player.RestartAnimation();
			}

			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				player.SetCurrentAnimation(shootR);
				player.RestartAnimation();
			}
		}

		if (e.type = SDL_KEYUP)
		{
			
		}

		//EVENTOS DE MOUSE
		SDL_GetMouseState(&mouseX, &mouseY);
	}
}

void Game::Draw(Object o)
{
	SDL_Rect dest = o.getDest();
	SDL_Rect src = o.getSource();
	SDL_RenderCopy(renderer, o.getTexture(), &src, &dest);
}

void Game::DrawFonts(const char* message, int x, int y, int r, int g, int b)
{
	SDL_Surface* surface;
	SDL_Texture* texture;

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