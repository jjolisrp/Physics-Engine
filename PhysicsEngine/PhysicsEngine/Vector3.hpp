#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

#include <stdio.h>
#include <Math.h>
#include "PhysicsEngineAPI.hpp"

struct PHYSICS_ENGINE_API Vector3
{
	float x;
	float y;
	float z;

	//Obtener la longitud del vector
	float GetLength() const {
		return sqrt(x * x + y * y + z * z);
	}

	//Obtener la distancia de un vector a otro
	float GetDistance(const Vector3& Other) const {
		using namespace std;
		return sqrt(
			pow(x - Other.x, 2) +
			pow(y - Other.y, 2) +
			pow(z - Other.z, 2)
		);
	}

	//Suma de dos vectores
	Vector3 operator+ (const Vector3& Other) const {
		return Vector3{
			x + Other.x,
			y + Other.y,
			z + Other.z
		};
	}

	//Resta de dos vectores
	Vector3 operator- (const Vector3& Other) const {
		return Vector3{
			x - Other.x,
			y - Other.y,
			z - Other.z
		};
	}

	//Multiplica el vector actual por un escalar
	Vector3 operator* (float multiplier) const {
		return Vector3{
			x * multiplier,
			y * multiplier,
			z * multiplier
		};
	}

	//Divide el vector actual por un escalar
	Vector3 operator/ (float divisor) const {
		return Vector3{
			x / divisor,
			y / divisor,
			z / divisor
		};
	}

	//Suma el vector actual con otro vector y guarda el resultado en la variable
	Vector3 operator+= (const Vector3& Other)
	{
		x += Other.x;
		y += Other.y;
		z += Other.z;
		return *this;
	}

	//Resta el vector actual con otro vector y guarda el resultado en la variable
	Vector3 operator-= (const Vector3& Other)
	{
		x -= Other.x;
		y -= Other.y;
		z -= Other.z;
		return *this;
	}

	//Multiplica el vector con un escalar y guarda el resultado en la variable
	Vector3 operator*= (float multiplier)
	{
		x *= multiplier;
		y *= multiplier;
		z *= multiplier;
		return *this;
	}

	//Divide el vector con un escalar y guarda el resultado en la variable
	Vector3 operator/= (float divisor)
	{
		x /= divisor;
		y /= divisor;
		z /= divisor;
		return *this;
	}

	//Usa el vector unitario para negar todo el vector
	Vector3 operator- () const {
		return Vector3{ -x, -y, -z };
	}

	void print()
	{
		printf("%f, %f, %f\n", x, y, z);
	}
};

#endif