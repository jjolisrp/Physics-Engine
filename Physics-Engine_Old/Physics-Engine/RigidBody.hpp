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

	void ApplyForce(RigidBody& rb, const Vector2& force);

	void SetPosition(RigidBody& rb, float x, float y);

	void SetVelocity(RigidBody& rb, float vX, float vY);

	void SetAcceleration(RigidBody& rb, float aX, float aY);

	
	Vector2 GetPosition(RigidBody& rb) { return position; }

	Vector2 GetVelocity(RigidBody& rb) { return position; }

	float GetPositionX(RigidBody& rb) { return position.GetComponentX(); }

	float GetPositionY(RigidBody& rb) { return position.GetComponentY(); }

	float GetVelocityX(RigidBody& rb) { return velocity.GetComponentX(); }

	float GetVelocityY(RigidBody& rb) { return velocity.GetComponentY(); }

	~RigidBody();
};

#endif