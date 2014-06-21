OBJS = src/summary_stats.o src/running_stats.o
CC = g++
CFLAGS = -std=c++0x -c -g -O3
LFLAGS = -std=c++0x -g -O3

summary_stats: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/summary_stats

src/summary_stats.o: src/running_stats.hpp src/summary_stats.cpp 
	$(CC) $(CFLAGS) src/summary_stats.cpp -o src/summary_stats.o

src/running_stats.o: src/running_stats.hpp src/running_stats.cpp 
	$(CC) $(CFLAGS) src/running_stats.cpp -o src/running_stats.o

clean:
	rm -rf src/*.o bin/sample
