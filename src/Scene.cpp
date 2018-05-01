#include "Scene.hpp"

Scene::Scene(){}

Scene::Scene(Sphere s){
	set.push_back(s);
}

Scene::Scene(std::vector<Sphere> s){
	set = s;
}

void Scene::addSphere(Sphere s){
	set.push_back(s);
}

void Scene::clear(){
	set.clear();
}

bool Scene::empty(){
	return set.empty();
}

std::ostream& operator<<(std::ostream& out, const Scene& s){
	out << "Scene{";
	for(int i = 0; i < s.set.size(); i++){
		out << "\n\t" << s.set[i];
		if (i < s.set.size() - 1)
			out << ";";
	}
	out << "}";
	return out;
}