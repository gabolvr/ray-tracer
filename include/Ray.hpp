#ifndef RAY
#define RAY

#include <iostream>
#include <utility>
#include "Vector3D.hpp"
#include "Sphere.hpp"

class Ray{

public:

	Vector3D point, direction;

	Ray(Vector3D p, Vector3D d);

	void setDirection(Vector3D d);

	bool intersect(Sphere& s);

	Vector3D intersection(Sphere& s);
};

std::ostream& operator<<(std::ostream& out, const Ray& r);

#endif
