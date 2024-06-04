#include "Collision.hpp"
#include <stdio.h>

Collision::Collision()
{

}

bool Collision::CheckBoxToBoxCollision(const AABB& box1, const AABB& box2)
{
	return
		(box1.min.x < box2.max.x && box1.max.x > box2.min.x) &&
		(box1.min.y < box2.max.y && box1.max.y > box2.min.y);
}

bool Collision::CheckCircleToCircleCollision()
{
	return false;
}

bool Collision::CheckBoxToCircleCollision()
{
	return false;
}

Collision::~Collision()
{

}