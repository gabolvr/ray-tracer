#ifndef SPHERE
#define SPHERE

#include <iostream>
#include "Vector3D.hpp"

class Sphere{

public:

	Vector3D center;
	double radius;
	uint8_t colorR, colorG, colorB;

	Sphere();
	Sphere(Vector3D c);
	Sphere(Vector3D c, double r);
	Sphere(Vector3D c, double r, uint8_t cR, uint8_t cG, uint8_t cB);
};

std::ostream& operator<<(std::ostream& out, const Sphere& s);

#endif