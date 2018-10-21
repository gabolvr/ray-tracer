#include "Image.hpp"

Image::Image(int w, int h){
	width = w;
	height = h;

	colorR.resize(height);
	colorG.resize(height);
	colorB.resize(height);

	for(int i = 0; i < height; i++){
		colorR[i].resize(width, 0);
		colorG[i].resize(width, 0);
		colorB[i].resize(width, 0);
	}
}

Image::Image(int s) : Image(s, s){}


Image::Image() : Image(100, 100){}

int Image::getWidth(){
	return width;
}

int Image::getHeight(){
	return height;
}

void Image::generateFile(std::string name){
	std::ofstream imageFile;
	imageFile.open("image/" + name + ".ppm");
	imageFile << "P3" << std::endl;
	imageFile << width << " " << height << std::endl << 255 << std::endl;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++)
			imageFile << colorR[i][j] << " " << colorG[i][j] << " " << colorB[i][j] << " ";
		imageFile << std::endl;
	}
}