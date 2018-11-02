#include "Sphere.hpp"

Sphere::Sphere(){
	center = Vector3D();
	radius = 1;

	ambient = Color(1);
	specular = Color(0.2);
	diffuse = Color(0.5);
	shininess = 10;
}

Sphere::Sphere(Vector3D c){
	center = c;
	radius = 1;

	ambient = Color(1);
	specular = Color(0.2);
	diffuse = Color(0.5);
	shininess = 10;
}

Sphere::Sphere(Vector3D c, double r){
	center = c;
	radius = r;

	ambient = Color(1);
	specular = Color(0.2);
	diffuse = Color(0.5);
	shininess = 10;
}

Sphere::Sphere(Vector3D c, double r, Color color){
	center = c;
	radius = r;

	ambient = color;
	specular = Color(0.2);
	diffuse = color * (0.5);
	shininess = 10;
}

Sphere::Sphere(Vector3D c, double r, Color amb, Color spec, Color diff){
	center = c;
	radius = r;

	ambient = amb;
	specular = spec;
	diffuse = diff;
	shininess = 10;
}

Sphere::Sphere(Vector3D c, double r, Color amb, Color spec, Color diff, int s){
	center = c;
	radius = r;

	ambient = amb;
	specular = spec;
	diffuse = diff;
	shininess = s;
}

bool Sphere::operator==(Sphere& s){
	return this->center == s.center && this->radius == s.radius && this->ambient == s.ambient && this->specular == s.specular
		&& this->diffuse == s.diffuse && this->shininess == s.shininess;
}

bool Sphere::operator!=(Sphere& s){
	return this->center != s.center || this->radius != s.radius || this->ambient != s.ambient || this->specular != s.specular
		|| this->diffuse != s.diffuse || this->shininess != s.shininess;
}

std::ostream& operator<<(std::ostream& out, const Sphere& s){
	out << "Sphere[" << s.center << "; " << s.radius << "; amb " << s.ambient << "; spec " << s.specular << "; diff " << s.diffuse << "; " << s.shininess << "]";
	return out;
}
