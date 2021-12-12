TARGET=a.out

all:
	g++ -Wall -pedantic -O2 -o ${TARGET} *.cpp *.hpp

.PHONY: clean
clean:
	rm -f *.gch ${TARGET}
