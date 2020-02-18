CC=g++
CFLAGS= -c -Wall -std=c++14
EXENAME= Chrono
default: main.o Chrono.o
	$(CC) main.o Chrono.o -o $(EXENAME)
Chrono.o: Chrono.cpp
	$(CC) $(CFLAGS) Chrono.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm *o $(EXENAME)
run:
	./$(EXENAME)
