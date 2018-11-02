#include "Color.hpp"
#include <algorithm>

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
	return Color(std::max(R * c.R, 0.0), std::max(G * c.G, 0.0), std::max(B * c.B, 0.0));
}

Color Color::operator*(double k){
	return Color(std::max(R * k, 0.0), std::max(G * k, 0.0), std::max(B * k, 0.0));
}

Color Color::operator+(Color c){
	return Color(std::min(R + c.R, 1.0), std::min(G + c.G, 1.0), std::min(B + c.B, 1.0));
}

void Color::operator*=(Color c){
	R = std::max(R * c.R, 0.0);
	G = std::max(G * c.G, 0.0);
	B = std::max(B * c.B, 0.0);
}

void Color::operator*=(double k){
	R = std::max(R * k, 0.0);
	G = std::max(G * k, 0.0);
	B = std::max(B * k, 0.0);
}

void Color::operator+=(Color c){
	R = std::min(R + c.R, 1.0);
	G = std::min(G + c.G, 1.0);
	B = std::min(B + c.B, 1.0);
}

bool Color::operator==(Color& c){
	return this->R == c.R && this->G == c.G && this->B == c.B;
}

bool Color::operator!=(Color& c){
	return this->R != c.R || this->G != c.G || this->B != c.B;
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
 
    out << "Color(R " << c.R  << ", G " << c.G << ", B " << c.B << ")";
     
    return out;
     
}

Color operator*(double k, Color c){
	return Color(std::max(c.R * k, 0.0), std::max(c.G * k, 0.0), std::max(c.B * k, 0.0));
}
