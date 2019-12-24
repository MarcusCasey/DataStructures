#make file template provided by esra edrin
CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0
O_FILES = PA05.o
all: $(O_FILES)
	$(CC) $(CXXFLAGS) $(O_FILES)
	rm -f *.o
PA05: main.cpp
	$(CC) $(CXXFLAGS) -c PA05.cpp -o PA05.o
clean:
	rm -f *.o
