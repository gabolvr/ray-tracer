#include "Light.hpp"

Light::Light(){
	source = Vector3D();
}

Light::Light(Vector3D s){
	source = s;
}

std::ostream& operator<<(std::ostream& out, const Light& l){
	out << "Light[" << l.source << "]";
	return out;
}