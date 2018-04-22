#ifndef VECTOR3D
#define VECTOR3D

#include <iostream>

class Vector3D {

public:

	double x, y, z;

	Vector3D();

	Vector3D(double r);

	Vector3D(double x, double y, double z);

	Vector3D operator+(Vector3D v);

	Vector3D operator-(Vector3D v);

	Vector3D operator*(Vector3D v);

	Vector3D operator*(double k);

	Vector3D operator/(double k);

	void operator+=(Vector3D v);

	void operator-=(Vector3D v);

	void operator*=(double k);

	void operator/=(double k);

	double norm();

	void normalize();

	Vector3D normalized();

	double distance(Vector3D v);

	bool operator==(Vector3D v);

	bool operator!=(Vector3D v);
};

std::ostream& operator<<(std::ostream& out, const Vector3D& v);

Vector3D operator*(double k, Vector3D v);

#endif