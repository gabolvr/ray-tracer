#ifndef CAMERA
#define CAMERA

#include <iostream>
#include <vector>
#include "Vector3D.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "Light.hpp"

class Camera {

public:

	Vector3D eye, target, up, right;
	double width, height;
	int pixelsW, pixelsH;
	Image image;

	Camera();
	Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h);
	void getImageFromScene(Scene& scene, std::vector<Light>& lights);

private:
	Color sphereColor(Sphere& sphere, Vector3D& point, Scene& scene, std::vector<Light>& lights);
	Color sphereIlumination(Sphere& sphere, Vector3D& point, Light& light);
};

std::ostream& operator<<(std::ostream& out, const Camera& c);

#endif
