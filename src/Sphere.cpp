#include "Sphere.hpp"

Sphere::Sphere(){
	center = Vector3D();
	radius = 1;
	colorR = colorG = colorB = 255;
}

Sphere::Sphere(Vector3D c){
	center = c;
	radius = 1;
	colorR = colorG = colorB = 255;
}

Sphere::Sphere(Vector3D c, double r){
	center = c;
	radius = r;
	colorR = colorG = colorB = 255;
}

Sphere::Sphere(Vector3D c, double r, uint8_t cR, uint8_t cG, uint8_t cB){
	center = c;
	radius = r;
	colorR = cR;
	colorG = cG;
	colorB = cB;
}

std::ostream& operator<<(std::ostream& out, const Sphere& s){
	out << "Sphere[" << s.center << "; " << s.radius << "; RGB(" << (int) s.colorR << ", " << (int) s.colorG << ", " << (int) s.colorB << ")]";
	return out;
}