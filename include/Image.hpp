#ifndef IMAGE
#define IMAGE

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Image {

private:
	int width, height;
	std::vector<std::vector<uint8_t> > colorR, colorG, colorB;

public:
	
	Image(int w, int h);

	Image(int s);

	Image();

	void resize(int w, int h);

	int getWidth();

	int getHeight();

	void setPixelColor(int i, int j, uint8_t R, uint8_t G, uint8_t B);

	void generateFile(std::string name);

};

#endif
