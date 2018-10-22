#ifndef SCENE
#define SCENE

#include <iostream>
#include <vector>
#include "Sphere.hpp"

class Scene{

public:
	
	std::vector<Sphere> set;
	Scene();
	Scene(Sphere s);
	Scene(std::vector<Sphere> s);
	void addSphere(Sphere s);
	void clear();
	bool empty();
	friend std::ostream& operator<<(std::ostream& out, const Scene& s);

};

#endif
