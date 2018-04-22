#include <iostream>
#include "Vector3D.hpp"

class Light {

public:
	
	Vector3D source;

	Light();
	Light(Vector3D s);
};

std::ostream& operator<<(std::ostream& out, const Light& l);