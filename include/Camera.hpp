#include <iostream>
#include "Vector3D.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Ray.hpp"

class Camera {

public:

	Vector3D eye, target, up, right;
	double width, height;
	int pixelsW, pixelsH;
	Image image;

	Camera();
	Camera(Vector3D e, Vector3D t, Vector3D u, double w, double h);
	void getImageFromScene(Scene& scene);
};

std::ostream& operator<<(std::ostream& out, const Camera& c);