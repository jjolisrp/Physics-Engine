#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <SDL.h>
#include <vector>
#include "Object.hpp"

class Entity : public Object
{
private:
	int health, maxHealth;
	struct cycle //This is for the animation
	{
		int row;
		int w;
		int h;
		int amount;
		int speed;
		int tick;
	};
	
	vector <cycle> animations;

	int curAnimation; //La animacion actual

	int begin;

public:
	Entity();

	void SetHealth(int h) { health = h; }

	void SetMaxhealth(int h) { maxHealth = h; }

	int getHealth() const { return health; }

	int getMaxHealth() const { return maxHealth; }

	int CreateCycle(int row, int w, int h, int amount, int speed);

	void SetCurrentAnimation(int c) { begin = 0; curAnimation = c; }

	void UpdateAnimation();

	~Entity();
};

#endif