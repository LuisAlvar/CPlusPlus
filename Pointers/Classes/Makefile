
compiler = g++
cflags = -Wall -g

solutionName = departmentTest

departmentTest: departmentTest.o
	$(compiler) $(cflags) -o $(solutionName) departmentTest.o

departmentTest.o: departmentTest.cpp department.h employee.h
	$(compiler) $(cflags) -c departmentTest.cpp

clean:
	rm *.o $(solutionName)
