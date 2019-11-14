run: main.o BigInt.o
	g++ main.o BigInt.o -o BigInt
BigInt.o: BigInt.cpp BigInt.hpp
	g++ -c BigInt.cpp
main.o: main.cpp BigInt.hpp
	g++ -c main.cpp
test.o: test.cpp BigInt.hpp
	g++ -c test.cpp
test: test.o BigInt.o
	g++ test.o BigInt.o -o test
	./test

