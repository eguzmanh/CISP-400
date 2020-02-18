#/* Your makefile must create main.o, RSA.o, and an executable named M02 */
CC=g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = M02

default: main.o RSA.o
	$(CC) main.o RSA.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
RSA.o: RSA.cpp RSA.h
	$(CC) $(CCFLAGS) RSA.cpp RSA.h
clean:
		rm*.o $(EXENAME)

run:
		./$(EXENAME)
