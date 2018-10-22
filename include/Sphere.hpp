#ifndef SPHERE
#define SPHERE

#include <iostream>
#include "Vector3D.hpp"
#include "Color.hpp"

class Sphere{

public:

	Vector3D center;
	double radius;
	Color color;

	Sphere();
	Sphere(Vector3D c);
	Sphere(Vector3D c, double r);
	Sphere(Vector3D c, double r, double R, double G, double B);
	Sphere(Vector3D c, double r, Color col);
};

std::ostream& operator<<(std::ostream& out, const Sphere& s);

#endif