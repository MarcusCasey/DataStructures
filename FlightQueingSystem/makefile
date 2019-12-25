#Marcus Casey CS 302
#Make File From CS 202 Template Provided by Esra Erdin
all: P3
P3: P3.cpp City.o flightMapv1.o Stack.o flightMapv2.o
	g++ P3.cpp City.o flightMapv1.o Stack.o flightMapv2.o -o P3
flightMapv1.o: flightMapv1.cpp City.o
	g++ -c flightMapv1.cpp
City.o: City.cpp
	g++ -c City.cpp
Stack.o: Stack.cpp
	g++ -c Stack.cpp
flightMapv2.o: flightMapv2.cpp
	g++ -c flightMapv2.cpp
clean:
	rm -rf *.o P3
