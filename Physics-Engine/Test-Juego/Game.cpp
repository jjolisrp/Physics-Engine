#include "Game.hpp"
#include <stdio.h>

const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGH = 500;
const int TILE_SIZE = 25;

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGH, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "First Game");

	TTF_Init();

	running = true;
	count = 0;

	//object1.SetDest(100, 100, 75, 75);
	//object1.SetSource(0, 0, 75, 75);
	//object1.SetImage("Raton.png", renderer);

	font = TTF_OpenFont("Sixty.ttf", 24);

	effect.Load("Retro.wav");
	effect.Play();

	player.SetImage("Player.png", renderer);
	player.SetDest(300, 100, 100, 106);
	idleR = player.CreateCycle(1, 96, 90, 5, 18);
	idleL = player.CreateCycle(2, 96, 95, 5, 18);
	walkR = player.CreateCycle(3, 96, 95, 8, 18);
	walkL = player.CreateCycle(4, 96, 95, 8, 18);
	shootR = player.CreateCycle(6, 96, 95, 5, 10);
	shootL = player.CreateCycle(5, 96, 95, 5, 10);
	player.SetCurrentAnimation(idleL);

	LoadMap("1.level");

	mapX = mapY = 0;

	scrollSpeed = 1;

	Loop();
}

void Game::Loop()
{
	static int lastTime = 0;

	while (running)
	{
		lastFrame = SDL_GetTicks();
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
	if (l)
	{
		if (player.getCurrentAnimation() != walkL)
		{
			player.SetCurrentAnimation(walkL);
		}
	}

	if (r)
	{
		if (player.getCurrentAnimation() != walkR)
		{
			player.SetCurrentAnimation(walkR);
		}
	}

	player.UpdateAnimation();
}

void Game::Renderer()
{
	SDL_SetRenderDrawColor(renderer, 23, 166, 195, 255);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGH;
	SDL_RenderFillRect(renderer, &rect);

	/*Draw(object1);
	DrawFonts("GAMEPLAY", 20, 30, 0, 0, 0);*/
	Draw(player);
	DrawMap();

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

			if (e.key.keysym.sym == SDLK_d)
			{
				l = 1;
				r = 0;
			}

			if (e.key.keysym.sym == SDLK_a)
			{
				r = 1;
				l = 0;
			}

			if (e.key.keysym.sym == SDLK_w)
			{
				u = 1;
			}

			if (e.key.keysym.sym == SDLK_s)
			{
				d = 1;
			}
		}

		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_d)
			{
				l = 0;

				player.ReverseAndAnimation(1, idleL);
			}

			if (e.key.keysym.sym == SDLK_a)
			{
				r = 0;

				player.ReverseAndAnimation(1, idleR);
			}

			if (e.key.keysym.sym == SDLK_w)
			{
				u = 0;
			}

			if (e.key.keysym.sym == SDLK_s)
			{
				d = 0;
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				player.SetCurrentAnimation(shootL);
			}

			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				player.SetCurrentAnimation(shootR);
			}
		}

		if (e.type == SDL_MOUSEBUTTONUP)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				player.ReverseAndAnimation(1, idleL);
			}

			if (e.button.button == SDL_BUTTON_RIGHT)
			{
				player.ReverseAndAnimation(1, idleR);
			}
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

void Game::LoadMap(const char* filename)
{
	Object tmp;

	tmp.SetImage("tileset.png", renderer);

	int current, mX, mY, mW, mH;

	ifstream in(filename);

	if (!in.is_open())
	{
		printf("Failed to open map file.\n");
		return;
	}

	in >> mW;
	in >> mH;
	in >> mX;
	in >> mY;

	for (int i = 0; i < mH; i++)
	{
		for (int j = 0; j < mW; j++)
		{
			if (in.eof())
			{
				printf("Reached end of map file too soon.\n");
				return;
			}

			in >> current;

			if (current != 0)
			{
				tmp.SetSolid(1);
				tmp.SetSource((current - 1) * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE);
				tmp.SetDest((j * TILE_SIZE) * mX, (i * TILE_SIZE) + mY, TILE_SIZE, TILE_SIZE);

				tmp.SetID(current);

				//Esto sirve para los objetos que no tienen un alfa de 255, es decir, que tienen opacidad
				/*if (current == 2 || current == 4)
				{
					tmp.SetSolid(0);
				}*/

				map.push_back(tmp);
			}
		}
	}

	in.close();
}

void Game::DrawMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i].getDX() >= mapX - TILE_SIZE && map[i].getDY() >= mapY - TILE_SIZE && map[i].getDX() <= mapX + SCREEN_WIDTH + TILE_SIZE && map[i].getDY() <= mapY + SCREEN_HEIGH + TILE_SIZE)
		{
			Draw(map[i]);
		}
	}
}

void Game::Scroll(int x, int y)
{
	/*for (int i = 0; i < map.size(); i++)
	{
		map[i].SetDest(map[i].getDX() + x, map[i].getDY() + y);
	}*/
}

Game::~Game()
{
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}