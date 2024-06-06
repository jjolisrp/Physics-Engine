#ifndef __RIGIDBODY_HPP__
#define __RIGIDBODY_HPP__

#include "Vector2.hpp"

class RigidBody
{
protected:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float mass;

public:
	RigidBody();

	void UpdateRigidBody(RigidBody& rb, float deltaTime);

	~RigidBody();
};

#endif