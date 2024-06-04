#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

#include "Vector3.hpp"
#include "Vector2.hpp"

struct AABB
{
	Vector2 max;
	Vector2 min;
};

class Collision
{
public:

	Collision();

	bool CheckBoxToBoxCollision(const AABB& box1, const AABB& box2);

	bool CheckCircleToCircleCollision();

	bool CheckBoxToCircleCollision();

	~Collision();
};

#endif