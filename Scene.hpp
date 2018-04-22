#include <iostream>
#include <vector>
#include "Sphere.hpp"

class Scene{

private:

	std::vector<Sphere> set;

public:
	Scene();
	Scene(Sphere s);
	Scene(std::vector<Sphere> s);
	void addSphere(Sphere s);
	void clear();
	bool empty();
	friend std::ostream& operator<<(std::ostream& out, const Scene& s);

};
