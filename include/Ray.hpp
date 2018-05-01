#include <iostream>
#include <utility>
#include "Vector3D.hpp"
#include "Sphere.hpp"

class Ray{

public:

	Vector3D point, direction;

	Ray(Vector3D p, Vector3D d);

	int intersect(Sphere s);

	std::pair<Vector3D, Vector3D> intersection(Sphere s);
};

std::ostream& operator<<(std::ostream& out, const Ray& r);