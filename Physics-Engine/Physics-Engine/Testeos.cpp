#include "Vector3.hpp"

int main()
{
	Vector3 v1;
	Vector3 v2;

	v1.x = 50;
	v1.y = 10;

	v2.x = 10;
	v2.y = 50;

	v1.print();
	v2.print();

	Vector3 v3;

	v3 = v1 + v2;

	v3.print();

	float longitud = v1.GetLength();
	printf("Longitud vector: %f\n", longitud);

	float distancia = v1.GetDistance(v2);
	printf("Ditancia entre v1 y v2: %f\n", distancia);
}