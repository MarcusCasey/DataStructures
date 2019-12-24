/**
 * Marcus Casey
 * CS302
 **/

#include "count.h"
// constructor
countingSort::countingSort() {
	size = 0;
	data = NULL;
	max = 0;
}
// copy constructor
countingSort::countingSort(int* takenData, int takenSize, int takenMax) {
	size = takenSize;
	data = takenData;
	max = takenMax;
}
// destructor
countingSort::~countingSort () {
	data = NULL;
}
// get num exchanges
int countingSort::getExchanges () {
	return previousExchange;
}
// get comparisons
int countingSort::getComparisons () {
	return previousComparison;

}
// main sorting fnc
int* countingSort::executeSort () {
	if (data == NULL || size == 0 || max == 0) {
		return NULL;
	}
	int countComparisons = 0;
	int countSwaps = 0;
	previousExchange = 0;
	previousComparison = 0;
	int count[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		int val = *(data + i);
		count[val]++;
		countComparisons++;
	}
	for (int i = 0; i < max; i++) {
		if (i == 0) {
			count[i] += 0;
		} else {
			count[i] += count[i - 1];
		}
	}
	int* tempData = new int[size];
	for (int i = 0; i < size; i++) {
		*(tempData + i) = *(data + i);
	}
	for (int i = 0; i < size; i++) {
		int val = *(tempData + i);
		int newPosition = count[val];
		*(data + (newPosition - 1)) = val;
		count[val]--;
		countSwaps++;
	}
	previousExchange = countSwaps;
	previousComparison = countComparisons;
	return data;
}
// main execute helper fnc
int* countingSort::executeSort (int* takenData, int takenSize, int takenMax) {
	size = takenSize;
	data = takenData;
	max = takenMax;
	if (data == NULL || size == 0 || max == 0) {
		return NULL;
	}
	return executeSort();
}
// output results to main console
void countingSort::outputFinal (int exchangeCount, int comparisonCount) {
	cout << "Counting  Info: " << endl << "\tSize: " << size << "\n\tComparisons: " << comparisonCount;
	cout << "\n\tSwaps/Exchanges: " << exchangeCount << endl;
	int* dataTrav = data;
	for (int i = 0; i < size; i++) {
		cout << *(dataTrav + i) << endl;
	}
	return;
}
