#include "Object.hpp"

Object::Object()
{
	solid = 1;
}

void Object::SetDest(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}

void Object::SetSource(int x, int y, int w, int h)
{
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void Object::SetImage(string filename, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	//texture = SDL_CreateTextureFromSurface(renderer, surface);
	texture = IMG_LoadTexture(renderer, filename.c_str());
}

Object::~Object()
{

}