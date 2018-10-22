#ifndef COLOR
#define COLOR

#include <iostream>

class Color {
public:
	double R, G, B;

	Color();

	Color(double C);

	Color(double R, double G, double B);

	Color operator*(Color c);

	Color operator*(double k);

	Color operator+(Color c);

	void operator*=(Color c);

	void operator*=(double k);

	void operator+=(Color c);

};

std::ostream& operator<<(std::ostream& out, const Color& c);

Color operator*(double k, Color c);

#endif
