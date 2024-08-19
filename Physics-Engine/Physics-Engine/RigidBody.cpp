#include "RigidBody.hpp"

RigidBody::RigidBody()
{
	position = { 0.0f, 0.0f };
	velocity = { 0.0f, 0.0f };
	acceleration = { 0.0f, 0.0f };
	mass = 10;
}

void RigidBody::UpdateRigidBody(RigidBody& rb, float deltaTime)
{
	rb.velocity += rb.acceleration * deltaTime;
	rb.position += rb.velocity * deltaTime;
}

void RigidBody::ApplyForce(RigidBody& rb, const Vector2& force)
{
	rb.acceleration = force / rb.mass;
}

void RigidBody::SetPosition(RigidBody& rb, float x, float y)
{
	rb.position.x = x;
	rb.position.y = y;
}

void RigidBody::SetVelocity(RigidBody& rb, float vX, float vY)
{
	rb.velocity.x = vX;
	rb.velocity.y = vY;
}

void RigidBody::SetAcceleration(RigidBody& rb, float aX, float aY)
{
	rb.acceleration.x = aX;
	rb.acceleration.y = aY;
}

RigidBody::~RigidBody()
{

}