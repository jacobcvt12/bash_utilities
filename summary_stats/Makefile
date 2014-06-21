OBJS = src/main.o src/srs.o src/comma.o
CC = g++
CFLAGS = -std=c++0x -c -g -O3
LFLAGS = -std=c++0x -g -O3

sample: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/sample

src/main.o: src/srs.hpp src/main.cpp 
	$(CC) $(CFLAGS) src/main.cpp -o src/main.o

src/srs.o: src/srs.hpp src/srs.cpp 
	$(CC) $(CFLAGS) src/srs.cpp -o src/srs.o

src/comma.o: src/comma.hpp src/comma.cpp 
	$(CC) $(CFLAGS) src/comma.cpp -o src/comma.o

clean:
	rm -rf src/*.o bin/sample
