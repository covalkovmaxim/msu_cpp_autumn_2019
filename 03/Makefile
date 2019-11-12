run: main.o Matrix.o
	g++ main.o Matrix.o -o matrix
Matrix.o: Matrix.cpp Matrix.hpp
	g++ -c Matrix.cpp
main.o: main.cpp Matrix.hpp
	g++ -c main.cpp
test.o: test.cpp Matrix.hpp
	g++ -c test.cpp
test: test.o Matrix.o
	g++ test.o Matrix.o -o test
	./test

