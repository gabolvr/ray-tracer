#include <iostream>
#include "Vector3D.hpp"

class Ray{

public:

	Vector3D point, direction;

	Ray(Vector3D p, Vector3D d);
};

std::ostream& operator<<(std::ostream& out, const Ray& r);