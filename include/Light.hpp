#ifndef LIGHT
#define LIGHT

#include <iostream>
#include "Vector3D.hpp"
#include "Color.hpp"

class Light {

public:
	
	Vector3D source;

	Color specular, diffuse;

	Light();
	Light(Vector3D s);
	Light(Vector3D s, Color c);
	Light(Vector3D s, Color spec, Color diff);
};

std::ostream& operator<<(std::ostream& out, const Light& l);

#endif
