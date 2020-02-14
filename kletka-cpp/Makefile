prog: main.o kletka.o
	g++ -o prog main.o kletka.o
main.o: main.cpp
	g++ -g -c main.cpp
kletka.o: kletka.cpp
	g++ -g -c kletka.cpp
clean:
	rm -rf prog *.o
