#include "Ray.hpp"

Ray::Ray(Vector3D p, Vector3D d){
	point = p;
	direction = d;
}

std::ostream& operator<<(std::ostream& out, const Ray& r){
	out << "Ray[" << r.point << "; " << r.direction << "]";
	return out;
}