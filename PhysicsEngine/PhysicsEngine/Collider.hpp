#ifndef __COLLIDER_HPP__
#define __COLLIDER_HPP__

#include "Vector3.hpp"
#include "Vector2.hpp"
#include "PhysicsEngineAPI.hpp"

struct PHYSICS_ENGINE_API Box
{
	Vector2 max;
	Vector2 min;
};

struct PHYSICS_ENGINE_API Circle
{
	float radius;
	Vector2 center;
};

class PHYSICS_ENGINE_API Collider
{
public:

	Collider();

	bool CheckBoxToBoxCollision(const Box& box1, const Box& box2);

	bool CheckCircleToCircleCollision(const Circle& circle1, const Circle& circle2);

	bool CheckBoxToCircleCollision(const Circle& circle, const Box& box);

	~Collider();
};

#endif