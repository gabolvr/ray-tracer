#ifndef IMAGE
#define IMAGE

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Color.hpp"

class Image {

private:
	int width, height;
	std::vector<std::vector<Color> > color;

public:
	
	Image(int w, int h);

	Image(int s);

	Image();

	void resize(int w, int h);

	int getWidth();

	int getHeight();

	void setPixelColor(int i, int j, Color c);

	void generateFile(std::string name);

};

#endif
