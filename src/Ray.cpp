#include "Ray.hpp"
#include <math.h>

Ray::Ray(Vector3D p, Vector3D d){
	point = p;
	direction = d.normalized();
}

void Ray::setDirection(Vector3D d){
	direction = d.normalized();
}

bool Ray::intersect(Sphere& s){

	// Sphere equation: || x - center || = radius
	// Line equation: x = point + k * direction
	// Solution: k^2 * <direction, direction> - k * 2 * <direction, center - point> + <center - point, center - point> - radius^2 = 0

	double delta = direction.scalar(s.center - point) * direction.scalar(s.center - point) - (s.center - point).scalar(s.center - point) + s.radius * s.radius;

	/*if(delta < 0)
		return 0;
	else if(delta == 0)
		return 1;
	return 2;*/

	return (delta > 0);
}

/*std::pair<Vector3D, Vector3D> Ray::intersection(Sphere s){

	// Sphere equation: || x - center || = radius
	// Line equation: x = point + k * direction
	// Solution: k^2 * <direction, direction> - k * 2 * <direction, center - point> + <center - point, center - point> - radius^2 = 0

	std::pair<Vector3D, Vector3D> intersection;
	//intersection.first = intersection.second = NULL;

	double delta = direction.scalar(s.center - point) * direction.scalar(s.center - point) - (s.center - point).scalar(s.center - point) + s.radius * s.radius;

	if (delta == 0){
		double k = direction.scalar(s.center - point);
		intersection.first = point + k * direction;
	}
	else if(delta > 0){
		double k1 = direction.scalar(s.center - point) + sqrt(delta);
		double k2 = direction.scalar(s.center - point) - sqrt(delta);
		intersection.first = point + k1 * direction;
		intersection.second = point + k2 * direction;
	}

	return intersection;
}*/

Vector3D Ray::intersection(Sphere& s){

	// Sphere equation: || x - center || = radius
	// Line equation: x = point + k * direction
	// Solution: k^2 * <direction, direction> - k * 2 * <direction, center - point> + <center - point, center - point> - radius^2 = 0

	Vector3D intersection1, intersection2;

	double delta = direction.scalar(s.center - point) * direction.scalar(s.center - point) - (s.center - point).scalar(s.center - point) + s.radius * s.radius;

	if (delta > 0){
		double k1 = direction.scalar(s.center - point) + sqrt(delta);
		double k2 = direction.scalar(s.center - point) - sqrt(delta);
		intersection1 = point + k1 * direction;
		intersection2 = point + k2 * direction;

		return point.distance(intersection1) < point.distance(intersection1) ? intersection1 : intersection2;
	}

	return Vector3D();
}

std::ostream& operator<<(std::ostream& out, const Ray& r){
	out << "Ray[" << r.point << "; " << r.direction << "]";
	return out;
}
