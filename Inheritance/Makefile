compiler = g++
cflags = -Wall -g

solutionName = clock

clocks: clocks.o
	$(compiler) $(cflags) -o $(solutionName) clocks.o

clocks.o: clocks.cpp clock.h time.h
	$(compiler) $(cflags) -c clocks.cpp

clean:
	rm *.o $(solutionName)
