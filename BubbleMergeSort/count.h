/**
 * Marcus Casey
 * CS302
 **/

#include <iostream>
#include <ctime>

using namespace std;

class countingSort {
	public:
		countingSort ();
		countingSort (int* data, int size, int max);
		~countingSort ();

		int getExchanges ();
		int getComparisons ();
		int* executeSort ();
		int* executeSort (int* data, int size, int max); 
		void outputFinal (int exchangeCount, int comparisonCount);

	private:
		int size;
		int* data;
		int max;
		int previousExchange;
		int previousComparison;
};
