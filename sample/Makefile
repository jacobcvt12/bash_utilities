sample: src/main.o src/reservoir.o src/comma.o
	g++ -std=c++0x -g src/comma.o src/reservoir.o src/main.o \
		-lm -o bin/sample -O3

main.o: src/main.cpp src/reservoir.hpp
	g++ -std=c++0x -g -c src/main.cpp -o src/reservoir.o -O3

reservoir.o: src/reservoir.cpp src/reservoir.hpp
	g++ -std=c++0x -g -c src/reservoir.cpp -o src/reservoir.o -O3

comma.o: src/comma.cpp src/comma.hpp
	g++ -std=c++0x -g -c src/comma.cpp -o src/comma.o -O3

clean:
	rm -rf src/*.o bin/sample
