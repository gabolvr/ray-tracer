#include <iostream>
#include "Vector3D.hpp"

class Camera {

public:

	Vector3D eye, target, up, right;
	double width, height;
	int pixelsW, pixelsH;

	Camera();
	Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h);
};

std::ostream& operator<<(std::ostream& out, const Camera& c);