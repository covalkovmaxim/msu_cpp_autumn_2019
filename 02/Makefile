all: run
linalloc.o: linalloc.cpp lib.hpp
	g++ -c -g linalloc.cpp -o linalloc.o
main.o: 1.cpp lib.hpp
	g++ -c -g 1.cpp -o main.o
run: main.o linalloc.o
	g++ main.o linalloc.o -o myalloc
test:
	python test.py
clean: 
	rm -rf main.o linalloc.o

