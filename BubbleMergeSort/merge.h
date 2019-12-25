/**
 * Marcus Casey
 * CS302
 **/

#include <iostream>
#include <ctime>
// not using std::
using namespace std;

class mergeSort {
	public:
		mergeSort ();
		mergeSort (int* data, int size);
		~mergeSort ();

		int* executeSort (int address1, int middleVal, int address2);
		int getExchangeNum ();
		int getComparisonNum ();
		void executeSort (int* data, int size); 
		void exchange (int* value_A, int* value_B);
		void outputFinal ();
		void resetCounts ();
		void executeSort (int address1, int address2);

	private:
		int size;
		int* data;
		int previousComparisonCount;
		int previousExchangeCount;

};

