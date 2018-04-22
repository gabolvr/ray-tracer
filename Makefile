CC = g++

Vector3D.o: Vector3D.cpp Vector3D.hpp
	$(CC) -c Vector3D.cpp

test.o: test.cpp Vector3D.hpp
	$(CC) -c test.cpp

test: test.o Vector3D.o
	$(CC) Vector3D.o test.o -o test