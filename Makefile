CC = g++

Vector3D.o: Vector3D.cpp Vector3D.hpp
	$(CC) -c Vector3D.cpp

Ray.o: Ray.cpp Ray.hpp Vector3D.hpp
	$(CC) -c Ray.cpp

Sphere.o: Sphere.cpp Sphere.hpp Vector3D.hpp
	$(CC) -c Sphere.cpp

Scene.o: Scene.cpp Scene.hpp Sphere.hpp
	$(CC) -c Scene.cpp

test.o: test.cpp Vector3D.hpp Ray.hpp Sphere.hpp Scene.hpp
	$(CC) -c test.cpp

test: test.o Vector3D.o Ray.o Sphere.o Scene.o
	$(CC) Vector3D.o Ray.o Sphere.o Scene.o test.o -o test

clean:
	rm -f test
	rm -f *.o
