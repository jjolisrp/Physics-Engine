#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

#include "Vector3.hpp"

class Collision
{
public:

	Collision();

	bool CheckBoxToBoxCollision();
	//bool CheckBoxToBoxCollision(AABB box1, AABB box2);


	bool CheckCircleToCircleCollision();

	bool CheckBoxToCircleCollision();

	~Collision();
};

#endif