#include "RigidBody.hpp"

RigidBody::RigidBody()
{
	position = { 0.0f, 0.0f };
	velocity = { 0.0f, 0.0f };
	acceleration = { 0.0f, 0.0f };
	mass = 0;
}

void RigidBody::UpdateRigidBody(RigidBody& rb, float deltaTime)
{
	rb.velocity += rb.acceleration * deltaTime;
	rb.position += rb.velocity * deltaTime;
}

RigidBody::~RigidBody()
{

}