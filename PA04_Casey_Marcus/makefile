# make file format provided by Esra Erdin CS 202
all: P4
P4: main.cpp bubble.o merge.o count.o
	g++ main.cpp bubble.o merge.o count.o -o P4 -std=c++11
bubble.o: bubble.cpp
	g++ -c bubble.cpp
merge.o: merge.cpp
	g++ -c merge.cpp
counting.o: count.cpp
	g++ -c count.cpp
clean:
	rm -rf *.o P4
