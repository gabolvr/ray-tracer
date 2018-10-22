CC = g++
CFLAGS = -std=c++11
INC = -I include

Vector3D.o: src/Vector3D.cpp include/Vector3D.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Vector3D.cpp -o build/Vector3D.o

Ray.o: src/Ray.cpp include/Ray.hpp include/Vector3D.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Ray.cpp -o build/Ray.o

Sphere.o: src/Sphere.cpp include/Sphere.hpp include/Vector3D.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Sphere.cpp -o build/Sphere.o

Scene.o: src/Scene.cpp include/Scene.hpp include/Sphere.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Scene.cpp -o build/Scene.o

Light.o: src/Light.cpp include/Light.hpp include/Vector3D.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Light.cpp -o build/Light.o

Image.o: src/Image.cpp include/Image.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Image.cpp -o build/Image.o

Camera.o: src/Camera.cpp include/Camera.hpp include/Vector3D.hpp include/Image.hpp include/Scene.hpp include/Ray.hpp
	$(CC) $(CFLAGS) $(INC) -c src/Camera.cpp -o build/Camera.o

test.o: src/test.cpp include/Vector3D.hpp include/Ray.hpp include/Sphere.hpp include/Scene.hpp include/Light.hpp include/Camera.hpp
	$(CC) $(CFLAGS) $(INC) -c src/test.cpp -o build/test.o

test: test.o Vector3D.o Ray.o Sphere.o Scene.o Light.o Camera.o Image.o
	$(CC) $(CFLAGS) $(INC) build/Vector3D.o build/Ray.o build/Sphere.o build/Scene.o build/Light.o build/Camera.o build/Image.o build/test.o -o test/test

clean:
	rm -f bin/*
	rm -f build/*.o
