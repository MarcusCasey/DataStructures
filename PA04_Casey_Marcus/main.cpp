/**
 * Marcus Casey
 * CS302
 **/

// import libraries
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

// import header files
#include "count.h"
#include "bubble.h"
#include "merge.h"


// not using std::
using namespace std;
// create numbers randomly, this was theory crafted after class
void createNums (int *firstVals, int numAmt);
// read in nums and seperate files
void readIn (int* firstVals, int numAmt, int fileNum);
// int main
int main () {
// after 3 runs end 	
	for (int i = 0; i < 3; i++) {
		int numAmt = 0;
		if (i == 0) {
			numAmt = 1000;
		} else if (i == 1) {
			numAmt = 10000;
		} else if (i == 2) {
			numAmt = 100000;
		} else {
			cout << "Uknown Error, ending program" << endl;
			return 0;
		}
		int* nums;
		nums = new int[numAmt];
		createNums(nums, numAmt);
		float bubbleTime = 0;
		float mergeTime = 0;
		float countTime = 0;
		int bubbleExchanges = 0;
		int bubbleComparisons = 0;
		int mergeExchanges = 0;
		int mergeComparisons = 0;
		int countExchanges = 0;
		int countComparisons = 0;


		// start bubble, read in values
		for (int i = 0; i < 10; i++) {
			readIn(nums, numAmt, i + 1); 
			bubbleSort bubble(nums, numAmt);
			clock_t elapsedTime;
			elapsedTime = clock();
			bubble.executeSort();
			elapsedTime = clock() - elapsedTime;
			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;
			bubbleTime = bubbleTime + lastTime;
			bubbleExchanges += bubble.getExchangeNum();
			bubbleComparisons += bubble.getComparisonNum();
		}
		bubbleTime = bubbleTime / 10;
		bubbleExchanges = bubbleExchanges / 10;
		bubbleComparisons = bubbleComparisons / 10;


		//merge sort start
		for (int i = 0; i < 10; i++) {
			readIn(nums, numAmt, i + 1); 
			mergeSort merge(nums, numAmt);
			merge.resetCounts();
			clock_t elapsedTime;
			elapsedTime = clock();
			merge.executeSort(0, numAmt - 1);
			elapsedTime = clock() - elapsedTime;
			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;
			mergeTime = mergeTime + lastTime;
			mergeExchanges += merge.getExchangeNum();
			mergeComparisons += merge.getComparisonNum();
		}
		mergeTime = mergeTime / 10;
		mergeExchanges = mergeExchanges / 10;
		mergeComparisons = mergeComparisons / 10;
		


		// counting sort start
		for (int i = 0; i < 10; i++) {
			readIn(nums, numAmt, i + 1); 
			countingSort count(nums, numAmt, 1000000);
			clock_t elapsedTime;
			elapsedTime = clock();
			count.executeSort();
			elapsedTime = clock() - elapsedTime;
			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;
			countTime =countTime + lastTime;
			countExchanges += count.getExchanges();
			countComparisons += count.getComparisons();
		}
		countTime = countTime / 10;
		countExchanges = countExchanges / 10;
		countComparisons = countComparisons / 10;
		cout << endl << "Average Sort Times" << numAmt << " Numbers: " << endl;
		cout << "\tMerge Sort: " << mergeTime << "s" << endl;
		cout << "\t\tAverage Swaps (Exchanges): " << mergeExchanges << " Average Comparisons: " << mergeComparisons << endl;
		cout << "\tBubble Sort: " << bubbleTime << "s" << endl;
		cout << "\t\tAverage Swaps(exchanges): " << bubbleExchanges << " Average Comparisons: " << bubbleComparisons << endl;
		cout << "\tCount Sort: " << countTime << "s" << endl;
		cout << "\t\tAverage Swaps (Exchanges): " << countExchanges << " Average Comparisons: " << countComparisons << endl;
	}
		cout << "Finished" << endl;
	createNums(NULL, 1);
	return 0;
}

// read nums in from fin. Used multiple files to generate different numbers, textbook
void readIn (int* firstVals, int numAmt, int fileNum) {
	ifstream fin;
	fin.open("Numbers" + to_string(fileNum) + ".txt");
	for (int i = 0; i < numAmt; i++) {
		fin >> *(firstVals + i);
	}
	return;
}

// generate nums for number files, almost as random as possible. Run 10 times.
void createNums (int *firstVals, int numAmt) {
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int* nums = new int[numAmt];
		int* moveVal = nums;
		for (int j = 0; j < numAmt; j++) {
			*(moveVal + j) = rand() % 1000001;
		}
		moveVal = NULL;
		ofstream outFile;
		outFile.open("Numbers" + to_string(i+1) + ".txt");
		for (int j = 0; j < (numAmt); j++) {
			outFile << *(nums + j) << endl;
		}
		outFile.close();
		delete[] nums;
	}
	return;
}
