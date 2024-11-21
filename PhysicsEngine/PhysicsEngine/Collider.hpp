#ifndef __COLLIDER_HPP__
#define __COLLIDER_HPP__

#include "Vector3.hpp"
#include "Vector2.hpp"

struct Box
{
	Vector2 max;
	Vector2 min;
};

struct Circle
{
	float radius;
	Vector2 center;
};

class Collider
{
public:

	Collider();

	bool CheckBoxToBoxCollision(const Box& box1, const Box& box2);

	bool CheckCircleToCircleCollision(const Circle& circle1, const Circle& circle2);

	bool CheckBoxToCircleCollision(const Circle& circle, const Box& box);

	~Collider();
};

#endif