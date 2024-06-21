#include "Entity.hpp"

Entity::Entity()
{
	reverse = 0;
}

int Entity::CreateCycle(int row, int w, int h, int amount, int speed)
{
	cycle tmp;
	tmp.row = row - 1;
	tmp.w = w;
	tmp.h = h;
	tmp.amount = amount;
	tmp.speed = speed;
	tmp.tick = 0;

	animations.push_back(tmp);

	return animations.size() -1;
}

void Entity::UpdateAnimation()
{
	SetSource(animations[curAnimation].w * animations[curAnimation].tick, animations[curAnimation].row* animations[curAnimation].h, animations[curAnimation].w, animations[curAnimation].h);
	if (begin > animations[curAnimation].speed)
	{
		if (!reverse)
		{
			animations[curAnimation].tick++;
		}

		if (reverse)
		{
			animations[curAnimation].tick--;
		}

		begin = 0;
	}

	begin++;

	if (animations[curAnimation].tick >= animations[curAnimation].amount)
	{
		animations[curAnimation].tick = 0;
	}

	if (animations[curAnimation].tick <= 0)
	{
		if (nAb)
		{
			curAnimation = newAnimation;
			nAb = 0;
			reverse = 0;
		}
		else
		{
			animations[curAnimation].tick = 0;
		}
	}
}

void Entity::Reverse(bool r)
{
	reverse = r;
}

void Entity::ReverseAndAnimation(bool r, int nA)
{
	reverse = r;
	nAb = 1;
	nA = newAnimation;
}

Entity::~Entity()
{
	
}