#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
using namespace std;

class Object
{
private:
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Texture* texture;
	bool solid;
	int id;

public:
	Object();

	SDL_Rect getDest() const { return dest; }
	SDL_Rect getSource() const { return src; }
	SDL_Texture* getTexture() const { return texture; }
	bool getSolid() const { return solid; }
	int getDX() { return dest.x; }
	int getDY() { return dest.y; }
	int getDW() { return dest.w; }
	int getDH() { return dest.h; }

	void SetDest(int x, int y, int w, int h);
	void SetSource(int x, int y, int w, int h);
	void SetImage(string filename, SDL_Renderer* renderer);
	void SetSolid(bool s) { solid = s; }
	void SetID(int i) { id = i; }

	~Object();
};

#endif