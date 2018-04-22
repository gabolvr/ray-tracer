#include <iostream>
#include "Vector3D.hpp"

class Sphere{

public:

	Vector3D center;
	double radius;
	int colorR, colorG, colorB;

	Sphere();
	Sphere(Vector3D c);
	Sphere(Vector3D c, double r);
	Sphere(Vector3D c, double r, int cR, int cG, int cB);
};

std::ostream& operator<<(std::ostream& out, const Sphere& s);