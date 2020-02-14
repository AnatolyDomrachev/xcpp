prog: main.o student.o
	g++ -o prog main.o student.o
main.o: main.cpp
	g++ -g -c main.cpp
student.o: student.cpp
	g++ -g -c student.cpp
clean:
	rm -rf prog *.o
