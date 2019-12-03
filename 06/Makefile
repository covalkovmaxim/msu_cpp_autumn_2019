prog: Format.o test.o
	g++ test.o Format.o -o test
Format.o: Format.cpp Format.hpp
	g++ -c Format.cpp
test.o: test.cpp Format.hpp
	g++ -c test.cpp
test: prog
	./test
clear: 
	rm -rf *.o test
