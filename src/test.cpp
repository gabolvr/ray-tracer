#include <iostream>
#include <vector>
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "Image.hpp"

using namespace std;

void testVector3D(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;

	// Operations
	cout << v2 + v3 << endl;
	cout << v2 - v3 << endl;
	cout << v2 * 5 << endl;
	cout << v3 / 2 << endl;
	cout << 2 * v2 << endl;
	
	// Norm and distance
	cout << v2.distance(v3) << endl;
	cout << v3.norm() << " " <<  v3.norm() * v3.norm() << endl;
	
	// Self change operations
	v2 += v3;
	v3 -= v2;
	cout << v2 << endl;
	cout << v3 << endl;
	v3 *= 2.2;
	cout << v3 << endl;
	v3 /= 1.1;
	cout << v3 << endl;
	v1 += v2;

	// Equality check
	cout << (v2 == v1) << endl;
	cout << (v2 == v3) << endl;
	cout << (v2 != v3) << endl;

	// Normalization
	cout << v2.normalized() << endl;
	cout << v2 << endl;
	v2.normalize();
	cout << v2 << " " << v2.norm() << endl;
	v3.normalize();
	cout << v3 << " " << v3.norm() << endl;

	// Cross product
	Vector3D a(3, -3, 1), b(4, 9, 2);
	cout << a * b << endl;

	// Projection
	Vector3D u(2, 3, 4), v(1, -1, 0);
	cout << u.projection(v).z << endl;
}

void testRay(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	Ray r1(v1, v2);
	cout << r1 << endl;
}

void testSphere(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	Sphere s1, s2(v1), s3(v1, 1), s4(v1, 1, 100, 100, 100);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

void testScene(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	Sphere s1, s2(v1), s3(v1, 1), s4(v1, 1, 100, 100, 100);
	vector<Sphere> set;
	set.push_back(s1);
	set.push_back(s2);
	set.push_back(s3);
	Scene scene1, scene2(s1), scene3(set);
	scene3.addSphere(s4);
	cout << scene1 << endl;
	cout << scene2 << endl;
	cout << scene3 << endl;
}

void testLight(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	Light l1, l2(v2);
	cout << l1 << endl;
	cout << l2 << endl;
}

void testCamera(){
	Camera cam(Vector3D(), Vector3D(0,1,0), Vector3D(0,0,1), 10, 10);
	cout << cam << endl;
	cout << cam.right << endl;
}

void testIntersection(){
	Sphere s(Vector3D(), 1);
	Ray r1(Vector3D(0.5,5,0), Vector3D(0,-3,0)), r2(Vector3D(0,1,-5), Vector3D(0,0,4)), r3(Vector3D(4,0,-0), Vector3D(-1,0,-1));
	cout << r1.intersect(s) << " " << r1.intersection(s) << endl;
	cout << r2.intersect(s) << " " << r2.intersection(s) << endl;
	cout << r3.intersect(s) << " " << r3.intersection(s) << endl;
}

void testImage(){
	Image img1, img2(200), img3(200, 300);
	cout << img1.getWidth() << " " << img1.getHeight() << endl;
	cout << img2.getWidth() << " " << img2.getHeight() << endl;
	cout << img3.getWidth() << " " << img3.getHeight() << endl;
	img1.generateFile("img1");
	img2.generateFile("img2");
	img3.generateFile("img3");
}

void testImageFromScene(){
	Camera cam(Vector3D(), Vector3D(5,0,0), Vector3D(0,1,0), 10, 10);
	Sphere s(Vector3D(10,0,0), 4.0, Color(0,0,0.5), Color(0.5), Color(0,0,0.5), 5);
	Scene scene(s);
	vector<Light> lights;
	lights.push_back(Light(Vector3D(0,5,2), Color(1)));
	cam.getImageFromScene(scene, lights);
	cam.image.generateFile("image-from-scene");
	cout << scene << endl;
	cout << lights[0] << endl;
}

void testImageDecompose(){
	Camera cam(Vector3D(), Vector3D(5,0,0), Vector3D(0,1,0), 6, 6);
	Sphere s0(Vector3D(10,0,0), 4.0, Color(0,0,0.5), Color(0.5), Color(0,0,0.5), 5);
	Sphere s1(Vector3D(10,0,0), 4.0, Color(0,0,0.5), Color(0), Color(0), 5);
	Sphere s2(Vector3D(10,0,0), 4.0, Color(0), Color(0.5), Color(0), 5);
	Sphere s3(Vector3D(10,0,0), 4.0, Color(0), Color(0), Color(0,0,0.5), 5);
	Scene composition(s0), ambient(s1), specular(s2), diffuse(s3);
	vector<Light> lights;
	lights.push_back(Light(Vector3D(0,5,2), Color(1)));
	
	cam.getImageFromScene(composition, lights);
	cam.image.generateFile("composition");

	cam.getImageFromScene(ambient, lights);
	cam.image.generateFile("ambient");

	cam.getImageFromScene(specular, lights);
	cam.image.generateFile("specular");

	cam.getImageFromScene(diffuse, lights);
	cam.image.generateFile("diffuse");	
}

void testEyeImage(){
	Camera cam(Vector3D(), Vector3D(5,0,0), Vector3D(0,1,0), 6, 6);
	Sphere s(Vector3D(14,0,0), 4.0, Color(1), Color(0.3), Color(0.5), 10);
	Scene scene(s);
	scene.addSphere(Sphere(Vector3D(8,0,0), 1.5, Color(0,0,0.5), Color(0.5), Color(0,0,0.5), 10));
	scene.addSphere(Sphere(Vector3D(5,0,0), 0.3, Color(0), Color(0.6), Color(0.1), 5));
	vector<Light> lights;
	lights.push_back(Light(Vector3D(0,5,2), Color(1)));
	cam.getImageFromScene(scene, lights);
	cam.image.generateFile("eye");
	cout << scene << endl;
}

void testEyePerspective(){
	Camera cam1(Vector3D(), Vector3D(5,0,0), Vector3D(0,1,0), 5, 5);
	Camera cam2(Vector3D(2,0,8), Vector3D(5,0,5), Vector3D(0,1,0), 5, 5);
	Sphere s(Vector3D(14,0,0), 4.0, Color(1), Color(0.3), Color(0.5), 10);
	Scene scene(s);
	scene.addSphere(Sphere(Vector3D(8,0,0), 1.5, Color(0,0,0.5), Color(0.5), Color(0,0,0.5), 10));
	scene.addSphere(Sphere(Vector3D(5,0,0), 0.3, Color(0), Color(0.6), Color(0.175), 5));
	vector<Light> lights;
	lights.push_back(Light(Vector3D(0,5,2), Color(1)));
	cam1.getImageFromScene(scene, lights);
	cam1.image.generateFile("eye1");
	cam2.getImageFromScene(scene, lights);
	cam2.image.generateFile("eye2");
}

int main(){
	// testVector3D();
	// testRay();
	//testSphere();
	// testScene();
	// testLight();
	// testCamera();
	// testIntersection();
	// testImage();
	// testImageFromScene();
	// testImageDecompose();
	// testEyeImage();
	testEyePerspective();
	return 0;
}
