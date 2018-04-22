#include "Vector3D.hpp"
#include <math.h>

Vector3D::Vector3D(){
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double r){
	this->x = r;
	this->y = r;
	this->z = r;
}

Vector3D::Vector3D(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D Vector3D::operator+(Vector3D v){
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(Vector3D v){
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Vector3D::operator*(double k){
	return Vector3D(x * k, y * k, z * k);
}

Vector3D Vector3D::operator/(double k){
	return Vector3D(x / k, y / k, z / k);
}

void Vector3D::operator+=(Vector3D v){
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3D::operator-=(Vector3D v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3D::operator*=(double k){
	x *= k;
	y *= k;
	z *= k;
}

void Vector3D::operator/=(double k){
	x /= k;
	y /= k;
	z /= k;
}

double Vector3D::norm(){
	return sqrt(x * x + y * y + z * z);
}

void Vector3D::normalize(){
	if (this->norm() != 0)
		(*this) /= this->norm();
}

Vector3D Vector3D::normalized(){
	if (this->norm() != 0)
		return (*this) / this->norm();
	return (*this);
}

double Vector3D::distance(Vector3D v){
	return (*this + v).norm();
}

bool Vector3D::operator==(Vector3D v){
	return this->x == v.x && this->y == v.y && this->z == z;
}

bool Vector3D::operator!=(Vector3D v){
	return this->x != v.x || this->y != v.y || this->z != z;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
 
    out << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
     
    return out;
     
}

Vector3D operator*(double k, Vector3D v){
	return Vector3D(v.x * k, v.y * k, v.z * k);
}
