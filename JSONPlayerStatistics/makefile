#make file format provided by esra erdin
# cs 202
CC=g++
all: main

main: P7.cpp mainParse.o
	g++ -std=c++11 P7.cpp mainParse.o -o P7

mainParse.o: mainParse.cpp
	g++ -c -std=c++11 mainParse.cpp

clean: rm -rf *.o main
