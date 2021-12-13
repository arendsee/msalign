TARGET=a.out

all:
	g++ -Wall -pedantic -O2 --std=c++11 *.cpp *.hpp

.PHONY: clean
clean:
	rm -f *.gch ${TARGET}
