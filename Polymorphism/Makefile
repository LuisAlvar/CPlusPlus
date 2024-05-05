compiler = g++

solutionName = worldclock

worldclock: worldclock.o
	$(compiler) -o $(solutionName) worldclock.o

worldclock.o: worldclock.cpp travelclock.h clock.h time.h
	$(compiler) -c worldclock.cpp

clean:
	rm *.o $(solutionName)
