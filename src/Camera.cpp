#include "Camera.hpp"

Camera::Camera(){}

Camera::Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h){
	eye = e;
	target = t;
	up = u;
	width = w;
	height = h;

	right = (target - eye) * up;
	right.normalize();
	pixelsW = 100;
	pixelsH = 100;
}

std::ostream& operator<<(std::ostream& out, const Camera& c){
	out << "Camera[" << c.eye << "; " << c.target << "; " << c.up << "; " << c.width << "x" << c.height << "]";
	return out;
}