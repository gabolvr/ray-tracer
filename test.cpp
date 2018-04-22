#include <iostream>
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

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
	cout << (v2 != v3) << endl;*/
	Ray r1(v1, v2);
	Sphere s1, s2(v1), s3(v1, 1), s4(v1, 1, 100, 100, 100);
	cout << r1 << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
}