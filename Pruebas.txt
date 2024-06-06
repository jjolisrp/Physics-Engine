#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Collision.hpp"

int main()
{
	//PRUEBAS DE LOS VECTORES (FUNCIONAN)
	Vector2 v1;
	Vector2 v2;

	v1.x = 50;
	v1.y = 10;

	v2.x = 10;
	v2.y = 50;

	v1.print();
	v2.print();

	Vector2 v3;

	v3 = v1 + v2;

	v3.print();

	float longitud = v1.GetLength();
	printf("Longitud vector: %f\n", longitud);

	float distancia = v1.GetDistance(v2);
	printf("Ditancia entre v1 y v2: %f\n", distancia);

	
	//Pruebas Colisiones BoxToBox (Funciona)
	int respuesta;

	Collision* c;
	c = new Collision();

	Box box1;
	box1.min = Vector2{ 0.0f, 0.0f };
	box1.max = Vector2{ 1.0f, 1.0f };

	Box box2;
	box2.min = Vector2{ 0.5f, 0.5f };
	box2.max = Vector2{ 1.5f, 1.5f };

	respuesta = c->CheckBoxToBoxCollision(box1, box2);
	
	if (respuesta == 1)
	{
		printf("Colisiona!!!\n");
	}
	else
	{
		printf("No Colisiona\n");
	}

	box1.min = Vector2{ 0.0f, 0.0f };
	box1.max = Vector2{ 1.0f, 1.0f };

	box2.min = Vector2{ 2.0f, 2.0f };
	box2.max = Vector2{ 3.0f, 3.0f };

	respuesta = c->CheckBoxToBoxCollision(box1, box2);

	if (respuesta == 1)
	{
		printf("Colisiona!!!\n");
	}
	else
	{
		printf("No Colisiona\n");
	}

	//Pruebas colisiones CircleToCirlce (Funciona)
	Circle circle1;
	circle1.center = Vector2{ 0.0f, 0.0f };
	circle1.radius = 3.0f;

	Circle circle2;
	circle2.center = Vector2{ 6.0f, 6.0f };
	circle2.radius = 2.0f;

	respuesta = c->CheckCircleToCircleCollision(circle1, circle2);

	if (respuesta == 1)
	{
		printf("Colisiona!!!\n");
	}
	else
	{
		printf("No Colisiona\n");
	}

	//Pruebas colisiones CircleToBox (Funciona)

	respuesta = c->CheckBoxToCircleCollision(circle1, box1);

	if (respuesta == 1)
	{
		printf("Colisiona!!!\n");
	}
	else
	{
		printf("No Colisiona\n");
	}
}

//ESTO ES PARTE DEL TESTEO DE LA SDL

/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
