#include "Light.hpp"

Light::Light(){
	source = Vector3D();
	specular = Color(1.0);
	diffuse = Color(1.0);
}

Light::Light(Vector3D s){
	source = s;
	specular = Color(1.0);
	diffuse = Color(1.0);
}

Light::Light(Vector3D s, Color c){
	source = s;
	specular = c;
	diffuse = c;
}

Light::Light(Vector3D s, Color spec, Color diff){
	source = s;
	specular = spec;
	diffuse = diff;
}

std::ostream& operator<<(std::ostream& out, const Light& l){
	out << "Light[" << l.source << ", " << l.specular << ", " << l.diffuse << "]";
	return out;
}