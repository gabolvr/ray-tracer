#ifndef SPHERE
#define SPHERE

#include <iostream>
#include <vector>
#include "Vector3D.hpp"
#include "Color.hpp"

class Sphere{

public:

	Vector3D center;
	double radius;

	Color ambient, specular, diffuse;
	int shininess;

	Sphere();
	Sphere(Vector3D c);
	Sphere(Vector3D c, double r);
	Sphere(Vector3D c, double r, Color color);
	Sphere(Vector3D c, double r, Color amb, Color spec, Color diff);
	Sphere(Vector3D c, double r, Color amb, Color spec, Color diff, int s);

	bool operator==(Sphere& s);
	bool operator!=(Sphere& s);
};

std::ostream& operator<<(std::ostream& out, const Sphere& s);

#endif
