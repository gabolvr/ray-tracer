#include <iostream>
#include <vector>
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Light.hpp"
#include "Camera.hpp"

using namespace std;

int main(){
	Vector3D v1, v2(1), v3(1, 2, 3);
	/*cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v2 + v3 << endl;
	cout << v2 - v3 << endl;
	cout << v2 * 5 << endl;
	cout << v3 / 2 << endl;
	cout << 2 * v2 << endl;
	cout << v2.distance(v1) << endl;
	cout << v3.norm() << " " <<  v3.norm() * v3.norm() << endl;
	v2 += v3;
	v3 -= v2;
	cout << v2 << endl;
	cout << v3 << endl;
	v3 *= 2.2;
	cout << v3 << endl;
	v3 /= 1.1;
	cout << v3 << endl;
	v1 += v2;
	cout << (v2 == v1) << endl;
	cout << (v2 == v3) << endl;
	cout << (v2 != v3) << endl;
	Ray r1(v1, v2);
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
	cout << v2.normalized() << endl;
	cout << v2 << endl;
	v2.normalize();
	cout << v2 << " " << v2.norm() << endl;
	v3.normalize();
	cout << v3 << " " << v3.norm() << endl;
	Light l1, l2(v2);
	cout << l1 << endl;
	cout << l2 << endl;
	Vector3D a(3, -3, 1), b(4, 9, 2);
	cout << a * b << endl;*/
	Camera cam(Vector3D(), Vector3D(0,1,0), Vector3D(0,0,1), 10, 10);
	cout << cam << endl;
	cout << cam.right << endl;
	return 0;
}