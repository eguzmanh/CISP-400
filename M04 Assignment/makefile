CC=g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = hello #M01 for assignment

default: main.o factorial.o hello.o
	$(CC) main.cpp factorial.cpp hello.cpp -o $(EXENAME)
main.o : main.cpp
	$(CC) $(CCFLAGS) main.cpp
factorial.o : factorial.cpp
	$(CC) $(CCFLAGS) factorial.cpp
hello.o : hello.cpp
	$(CC) $(CCFLAGS) hello.cpp

clean:
	rm*.o$(EXENAME)

run:
	./$(EXENAME)
