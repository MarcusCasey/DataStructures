/**
 * Marcus Casey
 * CS302
 **/
#include "bubble.h"
// constructor
bubbleSort::bubbleSort() {
	size = 0;
	data = NULL;
	previousExchange = 0;
	previousComparison = 0;
}
// copy constructor
bubbleSort::bubbleSort(int* sentData, int sentSize) {
	size = sentSize;
	data = sentData;
}
// destructor
bubbleSort::~bubbleSort () {
	data = NULL;
}
// main sorting function
int* bubbleSort::executeSort () {
	if (data == NULL || size == 0) {
		return NULL;
	}
	previousExchange = 0;
	previousComparison = 0;
	int countComparisons = 0;
	int countExchanges = 0;
	bool sorted = false;
	int pass = 1;
	while (!sorted && pass < size) {
		sorted = true;
		for (int i = 0; i < (size - pass); i++) {
			int nextPosition = i + 1;
			if (*(data + i) > *(data + nextPosition)) {
				exchange((data + i), (data + nextPosition));
				sorted = false;
				countExchanges++;
			}
			countComparisons++;
		}
		pass++;
	}
	previousExchange = countExchanges;
	previousComparison = countComparisons;
	return data;
}
// helper fnc
int* bubbleSort::executeSort (int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;
	if (data == NULL || size == 0)
	{
		return NULL;
	}
	return executeSort();
}
// get swaps num
int bubbleSort::getExchangeNum () {
	return previousExchange;
}
// get compare num
int bubbleSort::getComparisonNum () {
	return previousComparison;
}
// exchange num
void bubbleSort::exchange (int* firstVal, int* secondVal) {
	int temp = *secondVal;
	*secondVal = *firstVal;
	*firstVal = temp;
	return;
}
// output results for main console
void bubbleSort::outputResults (int exchangeCount, int comparisonCount) {
	cout << "Bubble Sort Stats: " << endl << "\tSize: " << size << "\n\tComparisons: " << comparisonCount;
	cout << "\n\texchanges: " << exchangeCount << endl;
	int* dataTrav = data;
	for (int i = 0; i < size; i++) {
		cout << *(dataTrav + i) << endl;
	}
	return;
}
