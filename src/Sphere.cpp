#include "Sphere.hpp"

Sphere::Sphere(){
	center = Vector3D();
	radius = 1;
	color = Color(1.0);
}

Sphere::Sphere(Vector3D c){
	center = c;
	radius = 1;
	color = Color(1.0);
}

Sphere::Sphere(Vector3D c, double r){
	center = c;
	radius = r;
	color = Color(1.0);
}

Sphere::Sphere(Vector3D c, double r, double R, double G, double B){
	center = c;
	radius = r;
	color = Color(R, G, B);
}

Sphere::Sphere(Vector3D c, double r, Color col){
	center = c;
	radius = r;
	color = col;
}

std::ostream& operator<<(std::ostream& out, const Sphere& s){
	out << "Sphere[" << s.center << "; " << s.radius << "; " << s.color << "]";
	return out;
}