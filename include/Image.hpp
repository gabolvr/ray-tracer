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

	int getWidth();

	int getHeight();

	void generateFile(std::string name);

};
