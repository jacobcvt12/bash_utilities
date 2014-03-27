OBJS = src/main.o src/reservoir.o src/comma.o
CC = g++
CFLAGS = -std=c++0x -c -g -O3
LFLAGS = -std=c++0x -g -O3

sample: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/sample

src/main.o: src/reservoir.hpp src/main.cpp 
	$(CC) $(CFLAGS) src/main.cpp -o src/main.o

src/reservoir.o: src/reservoir.hpp src/reservoir.cpp 
	$(CC) $(CFLAGS) src/reservoir.cpp -o src/reservoir.o

src/comma.o: src/comma.hpp src/comma.cpp 
	$(CC) $(CFLAGS) src/comma.cpp -o src/comma.o

clean:
	rm -rf src/*.o bin/sample
