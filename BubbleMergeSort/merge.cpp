/**
 * Marcus Casey
 * CS302
 **/

#include "merge.h"
// constructor
mergeSort::mergeSort() {
	size = 0;
	data = NULL;
	previousComparisonCount = 0;
	previousExchangeCount = 0;

}
// copy constructor
mergeSort::mergeSort(int* sentData, int sentSize) {
	size = sentSize;
	data = sentData;
	previousComparisonCount = 0;
	previousExchangeCount = 0;
}
// destructor
mergeSort::~mergeSort () {
	data = NULL;
}
// main sorting fnc
int* mergeSort::executeSort (int address1, int middleVal, int address2) {
	if (data == NULL || size == 0) {
		return NULL;
	}
	int countComparisons = 0;
	int countExchanges = 0;
	int val1 = address1;
	int val2 = middleVal;
	int val3 = middleVal + 1;
	int val4 = address2;
	int index = val1;
	int* tempArray = new int[size];
// logic of a basic merge
	while (val1 <= val2 && val3 <= val4) {
		if (*(data + val1) <= *(data + val3)) {
			*(tempArray + index) = *(data + val1);
			countExchanges++;
			val1++;
		} else {
			*(tempArray + index) = *(data + val3);
			countExchanges++;
			val3++;
		}
		countComparisons++;
		index++;
	}
	while (val1 <= val2) {
		*(tempArray + index) = *(data + val1);
		val1++;
		index++;
		countExchanges++;
	}
	while (val3 <= val4) {
		*(tempArray + index) = *(data + val3);
		val3++;
		index++;
		countExchanges++;
	}
	for (index = address1; index <= address2; index++) {
		*(data + index) = *(tempArray + index);
	}
	previousComparisonCount += countComparisons;
	previousExchangeCount += countExchanges;
	delete[] tempArray;
	tempArray = NULL;

	return data;
}
// execute helper
void mergeSort::executeSort (int* sentData, int sentSize) {
	size = sentSize;
	data = sentData;
	if (data == NULL || size == 0) {
		return;
	}
	return executeSort(0, size - 1);
}
// swap
void mergeSort::exchange (int* value_A, int* value_B) {
	int temp = *value_B;
	*value_B = *value_A;
	*value_A = temp;
	return;
}
// print final results
void mergeSort::outputFinal () {
	cout << "Merge Info: " << endl << "\tSize: " << size << "\n\tComparisons: " << previousComparisonCount;
	cout << "\nSwap/Exchanges: " << previousExchangeCount << endl;
	int* dataTrav = data;
	for (int i = 0; i < size; i++) {
		cout << *(dataTrav + i) << endl;
	}
	return;
}
// reset comparisons, needed.
void mergeSort::resetCounts () {
	previousExchangeCount = 0;
	previousComparisonCount = 0;
}
// get exchange nums
int mergeSort::getExchangeNum () {
	return previousExchangeCount;
}
// get comparison num
int mergeSort::getComparisonNum ()
{
	return previousComparisonCount;
}
// execute sort help
void mergeSort::executeSort (int address1, int address2) {
	if (address1 < address2) {
		int middleVal = address1 + (address2 - address1)/2;
		executeSort(address1, middleVal);
		executeSort(middleVal + 1, address2);
		executeSort(address1, middleVal, address2);
	}
	return;
}
