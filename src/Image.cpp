#include "Image.hpp"

Image::Image(int w, int h){
	resize(w, h);
}

Image::Image(int s) : Image(s, s){}

Image::Image() : Image(100, 100){}

void Image::resize(int w, int h){
	width = w;
	height = h;

	color.resize(height);

	for(int i = 0; i < height; i++)
		color[i].resize(width, Color());
}

int Image::getWidth(){
	return width;
}

int Image::getHeight(){
	return height;
}

void Image::setPixelColor(int i, int j, Color c){
	color[i][j] = c;
}

void Image::generateFile(std::string name){
	std::ofstream imageFile;
	imageFile.open("image/" + name + ".ppm");
	imageFile << "P3" << std::endl;
	imageFile << width << " " << height << std::endl << 255 << std::endl;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			imageFile << (int) (255 * color[i][j].R) << " "
				<< (int) (255 * color[i][j].G) << " " << (int) (255 * color[i][j].B) << " ";
		}
		imageFile << std::endl;
	}
}