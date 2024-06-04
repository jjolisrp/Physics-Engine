#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include <stdio.h>
#include <Math.h>

struct Vector2
{
	float x;
	float y;

	//Obtener la longitud del vector
	float GetLength() const {
		return sqrt(x * x + y * y);
	}

	//Obtener la distancia de un vector a otro
	float GetDistance(const Vector2& Other) const {
		using namespace std;
		return sqrt(
			pow(x - Other.x, 2) +
			pow(y - Other.y, 2)
		);
	}

	//Suma de dos vectores
	Vector2 operator+ (const Vector2& Other) const {
		return Vector2{
			x + Other.x,
			y + Other.y
		};
	}

	//Resta de dos vectores
	Vector2 operator- (const Vector2& Other) const {
		return Vector2{
			x - Other.x,
			y - Other.y
		};
	}

	//Multiplica el vector actual por un escalar
	Vector2 operator* (float multiplier) const {
		return Vector2{
			x * multiplier,
			y * multiplier
		};
	}

	//Divide el vector actual por un escalar
	Vector2 operator/ (float divisor) const {
		return Vector2{
			x / divisor,
			y / divisor
		};
	}

	//Suma el vector actual con otro vector y guarda el resultado en la variable
	Vector2 operator+= (const Vector2& Other)
	{
		x += Other.x;
		y += Other.y;
		return *this;
	}

	//Resta el vector actual con otro vector y guarda el resultado en la variable
	Vector2 operator-= (const Vector2& Other)
	{
		x -= Other.x;
		y -= Other.y;
		return *this;
	}

	//Multiplica el vector con un escalar y guarda el resultado en la variable
	Vector2 operator*= (float multiplier)
	{
		x *= multiplier;
		y *= multiplier;
		return *this;
	}

	//Divide el vector con un escalar y guarda el resultado en la variable
	Vector2 operator/= (float divisor)
	{
		x /= divisor;
		y /= divisor;
		return *this;
	}

	//Usa el vector unitario para negar todo el vector
	Vector2 operator- () const {
		return Vector2{ -x, -y};
	}

	void print()
	{
		printf("%f, %f\n", x, y);
	}
};

#endif