#ifndef __COLLISION_HPP__
#define __COLLISION_HPP__

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

class Collision
{
private:

	Box boxCollider;
	Circle circleCollider;

public:

	Collision();

	bool CheckBoxToBoxCollision(const Box& box1, const Box& box2);

	bool CheckCircleToCircleCollision(const Circle& circle1, const Circle& circle2);

	bool CheckBoxToCircleCollision(const Circle& circle, const Box& box);

	void SetBoxColliderParameters(Collision& collider, Vector2& max, Vector2& min);

	void SetMax(Collision& collider, Vector2& max);

	void SetMin(Collision& collider, Vector2& min);


	Box GetBoxCollider() { return boxCollider; }

	Vector2 GetMax() { return boxCollider.max; }

	Vector2 GetMin() { return boxCollider.min; }

	~Collision();
};

#endif