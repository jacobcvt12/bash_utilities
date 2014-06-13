OBJS = main.o fishmoore.o
CC = g++
CFLAGS = -std=c++0x -c -g -O3
LFLAGS = -std=c++0x -g -O3

fishmoore: $(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o fishmoore

main.o: fishmoore.hpp main.cpp 
		$(CC) $(CFLAGS) main.cpp -o main.o

srs.o: fishmoore.hpp fishmoore.cpp 
		$(CC) $(CFLAGS) fishmoore.cpp -o fishmoore.o

clean:
		rm -rf *.o fishmoore
