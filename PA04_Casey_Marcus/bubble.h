/**
 * Marcus Casey
 * CS302
 **/

#include <iostream>
#include <ctime>
// not using std::
using namespace std;

class bubbleSort {
	public:
		bubbleSort ();
		bubbleSort (int* data, int size);
		~bubbleSort ();

		int* executeSort ();	
		int* executeSort (int* data, int size); 
		int getExchangeNum ();
		int getComparisonNum ();
		void exchange (int* value_A, int* value_B);
		void outputResults (int exchangeCount, int comparisonCount);
		
	private:
		int size;
		int* data;
		int previousExchange;
		int previousComparison;
};
