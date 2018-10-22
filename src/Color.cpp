#include "Color.hpp"

Color::Color(){
	R = 0;
	G = 0;
	B = 0;
}

Color::Color(double C){
	R = C;
	G = C;
	B = C;
}

Color::Color(double R, double G, double B){
	this->R = R;
	this->G = G;
	this->B = B;
}

Color Color::operator*(Color c){
	return Color(R * c.R, G * c.G, B * c.B);
}

Color Color::operator*(double k){
	return Color(R * k, G * k, B * k);
}

Color Color::operator+(Color c){
	return Color(R + c.R, G + c.G, B + c.B);
}

void Color::operator*=(Color c){
	R *= c.R;
	G *= c.G;
	B *= c.B;
}

void Color::operator*=(double k){
	R *= k;
	G *= k;
	B *= k;
}

void Color::operator+=(Color c){
	R += c.R;
	G += c.G;
	B += c.B;
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
 
    out << "Color(R " << c.R  << ", G " << c.G << ", B " << c.B << ")";
     
    return out;
     
}

Color operator*(double k, Color c){
	return Color(c.R * k, c.G * k, c.B * k);
}
