/**
 * Marcus Casey
 * CS302
 * Provided CS202 Stack.cpp - Fall 2016 - Esra Edrin - Project X
**/

#ifndef STACK_CLASS
#define STACK_CLASS
#include <iostream>
#include <fstream>

using namespace std;

template<class itemType>
class Stack {
	public:
		Stack(int size = 10);
		Stack(const Stack<itemType>&);
		~Stack();

		bool push(itemType);
		itemType pop();
		bool isEmpty() const;
		bool isFull() const;
		bool clear();
		itemType peek();
		void print();
		void printFlights();
		void printFlightsToLog (ofstream* logFile);

	private:
		int max;
		int top;
		itemType* data;
};

// Default Constructor
template<class itemType>
Stack<itemType>::Stack(int size) {
	max = size;
	top = -1;
	data = new itemType[max];
}

// Copy Constructor
template<class itemType>
Stack<itemType>::Stack(const Stack<itemType>& sentStack) {
	max = sentStack.max;
	top = sentStack.top;
	data = new itemType[max];
	itemType *dataTrav = data;
	itemType *sentTrav = sentStack.data;
	for (int i = 0; i < max; i++) {
		*dataTrav = *sentTrav;
		dataTrav++;
		sentTrav++;
	}
	dataTrav = NULL;
	sentTrav = NULL;
}

// Destructor
template<class itemType>
Stack<itemType>::~Stack() {
	delete[] data;
	data = NULL;
}

template<class itemType>
bool Stack<itemType>::push(itemType value) {
	if (top + 1 == max) {
		return false;
	} else if (top + 1 < max) {
		itemType* dataTrav = data;
		for (int i = 0; i <= top; i++) {
			dataTrav++;
		}
		*dataTrav = value;
		top++;
		dataTrav = NULL;
		return true;
	}
}

template<class itemType>
itemType Stack<itemType>::pop() {
	if (top != -1) {
		itemType* dataTrav = data;
		for (int i = 0; i < top; i++) {
			dataTrav++;
		}
		top--;
		return *dataTrav;
	} else{
		return NULL;
	}
}

template<class itemType>
bool Stack<itemType>::isEmpty() const {
	if (top == -1) {
		return true;
	} else {
		return false;
	}
}

template<class itemType>
bool Stack<itemType>::isFull() const {
	if (top + 1 == max) {
		return true;
	} else {
		return false;
	}
}

template<class itemType>
bool Stack<itemType>::clear() {
	delete[] data;
	data = NULL;
	data = new itemType[max];
	top = -1;
	return true;
}

template<class itemType>
itemType Stack<itemType>::peek() {
	if (top == -1) {
		return NULL;
	} else {
		itemType *dataTrav = data;
		for (int i = 0; i < top; i++) {
			dataTrav++;
		}
		return *dataTrav;
	}
}

template<class itemType>
void Stack<itemType>::print() {
	cout << "Max: " << max << "\t\tTop: " << top << endl;
	cout <<"Contents: {";
	if (top != -1) {
		itemType* dataTrav = data;
		for (int i = 0; i < top + 1; i++) {
			if (i == top) {
				cout << *dataTrav << " (TOP)";
			} else {
				cout << *dataTrav << ", ";
			}
			dataTrav++;
		}
		dataTrav = NULL;
	} else {
		cout << "EMPTY";
	}
	cout << "}" << endl;
	return;
}

template<class itemType>
void Stack<itemType>::printFlights() {
	cout <<"Route: ";
	if (top != -1) {
		itemType* dataTrav = data;
		for (int i = 0; i < top + 1; i++) {
			if (i == top) {
				cout << *dataTrav;
			} else {
				cout << *dataTrav << " -> ";
			}
			dataTrav++;
		}
		dataTrav = NULL;
	} else {
		cout << "ERROR: NONE";
	}
	cout << "Number of stops: " << top + 1 << endl;
	return;
}
template<class itemType>
void Stack<itemType>::printFlightsToLog (ofstream* logFile) {
	(*logFile) << "Contents of stack after isPath: " << endl;
	(*logFile) << "Route: ";
	if (top != -1) {
		itemType* dataTrav = data;
		for (int i = 0; i < top + 1; i++) {
			if (i == top) {
				(*logFile) << *dataTrav;
			} else {
				(*logFile) << *dataTrav << " -> ";
			}
			dataTrav++;
		}
		dataTrav = NULL;
	} else {
		(*logFile) << "ERROR: NONE";
	}
	(*logFile) << "Number of stops: " << top + 1 << endl;
	return;
}
#endif
