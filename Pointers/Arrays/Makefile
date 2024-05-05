
compiler = g++
cflags = -Wall -g

solutionName = pa

pointersInArrays: pointersInArrays.o
	$(compiler) $(cflags) -o $(solutionName) pointersInArrays.o

pointersInArrays.o: pointersInArrays.cpp
	$(compiler) $(cflags) -c pointersInArrays.cpp

clean:
	rm *.o $(solutionName)
