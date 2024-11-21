#include "Collider.hpp"
#include <stdio.h>

Collider::Collider()
{

}

bool Collider::CheckBoxToBoxCollision(const Box& box1, const Box& box2)
{
	return
		(box1.min.x < box2.max.x && box1.max.x > box2.min.x) &&
		(box1.min.y < box2.max.y && box1.max.y > box2.min.y);
}

bool Collider::CheckCircleToCircleCollision(const Circle& circle1, const Circle& circle2)
{
	float distance = circle1.center.GetDistance(circle2.center);

	return (distance < circle1.radius + circle2.radius);
}

bool Collider::CheckBoxToCircleCollision(const Circle& circle, const Box& box)
{
	//Box perimeter following the circle position
	float px = circle.center.x;
	if (px < box.min.x) { px = box.min.x; }
	if (px > box.max.x) { px = box.max.x; }

	float py = circle.center.y;
	if (py < box.min.y) { py = box.min.y; }
	if (py > box.max.y) { py = box.max.y; }
	//

	float distance = circle.center.GetDistance(Vector2{ px, py });

	return (distance < circle.radius);
}

Collider::~Collider()
{

}