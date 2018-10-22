#include "Camera.hpp"

Camera::Camera(){}

Camera::Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h){
	eye = e;
	target = t;
	up = u.normalized();
	width = w;
	height = h;

	right = (target - eye) * up;
	right.normalize();
	pixelsW = 1000;
	pixelsH = 1000;

	image.resize(pixelsW, pixelsH);
}

void Camera::getImageFromScene(Scene& scene){
	Vector3D top = target + ((height / 2.0) * up) - ((width / 2.0) * right);

	Vector3D rayDirection;

	Vector3D stepRight = ((1.0 * width) / pixelsW) * right;
	Vector3D stepDown = ((-1.0 * height) / pixelsH) * up;

	Ray ray(eye, rayDirection);

	for(int i = 0; i < pixelsH; i++){
		rayDirection = top - eye + (i * stepDown);

		for(int j = 0; j < pixelsW; j++, rayDirection += stepRight){
			ray.setDirection(rayDirection);
			
			for(Sphere s : scene.set){
				if(ray.intersect(s))
					image.setPixelColor(i, j, s.colorR, s.colorG, s.colorB);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Camera& c){
	out << "Camera[" << c.eye << "; " << c.target << "; " << c.up << "; " << c.width << "x" << c.height << "]";
	return out;
}