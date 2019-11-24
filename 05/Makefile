run: main.o
	g++ main.o --std=c++14 -o ser
main.o: main.cpp Serializer.hpp
	g++ -c main.cpp
test: run
	./ser 
clear:
	rm -rf *.o test
