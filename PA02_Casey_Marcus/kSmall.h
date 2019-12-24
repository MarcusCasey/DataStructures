#ifndef KSMALL_H
#define KSMALL_H
#include <fstream>
#include <iostream> 
#include <string>
using namespace std;

class kSmall {


public:
	kSmall();
	~kSmall();
	int findKth(const int& kVal, const int& firstSelect, const int& lastSelect, const int& length);
	int partition(const int& firstSelect, const int& lastSelect);
	int analyzeArr(const string& fileName);
	void logCalc(const int& pivot, const int& firstSelect, const int& length);


private:
	int* currentAmt;
	int kVal;
	string log;
};

// constructor
kSmall::kSmall() {	
	kVal = 0;
	currentAmt = nullptr;
	remove("log.txt");
	log = "Log representation of code. Pivot is indicated with {} Array Vals [].\n\n\n";
}

// destructor and set to nullptr
kSmall::~kSmall() {
	delete[] currentAmt;
	currentAmt = nullptr;
}

// findKth kVal val
int kSmall::findKth(const int& kNum, const int& firstSelect, const int& lastSelect, const int& length) {
	kVal = kNum;
	if((kVal>0) && (kVal < length-firstSelect+1)) {
	
		int pivot = partition(firstSelect, lastSelect);
		logCalc(pivot, firstSelect, length);
		
	if(kVal<pivot-firstSelect+1) {
		return findKth(kVal, firstSelect, pivot-1, length);	
	
	} else if(kVal==pivot-firstSelect+1) {
		return currentAmt[pivot];
	
	} else {
		return findKth(kVal-(pivot-firstSelect+1), pivot+1, lastSelect, length);
		}
	}
	return -1;
}
// partition calced value
int kSmall::partition(const int& firstSelect, const int& lastSelect) {
	int pivot=firstSelect;
	for(int swapVal=firstSelect; swapVal < lastSelect; swapVal++) {
		if(currentAmt[swapVal] < currentAmt[lastSelect]) {
			int tempHold = currentAmt[pivot];
			currentAmt[pivot] = currentAmt[swapVal];
			currentAmt[swapVal] = tempHold;
			pivot++;
		}
	}
	int tempHold = currentAmt[pivot];
	currentAmt[pivot] = currentAmt[lastSelect];
	currentAmt[lastSelect] = tempHold;
	return pivot;
}
// go through array, make an array as long as length after counting length of file
int kSmall::analyzeArr(const string& fileName) {
	ifstream fin;
	fin.open(fileName);
	int numCount = 0;
	int* tempHold = new int[1000];
	int length = 0;

	while(fin>>tempHold[numCount]) {
		length++;
		numCount++;
	}
	currentAmt = new int[length]; 
	for(int arrWidth=0; arrWidth<length; arrWidth++) {
		currentAmt[arrWidth]=tempHold[arrWidth];
	}
	delete[] tempHold;
	tempHold = nullptr;
	fin.close();
	return length;
}
// create log document documenting calcing ksmall
void kSmall::logCalc(const int& pivot, const int& firstSelect, const int& length) { 
	ifstream fin;
	ofstream fout;
	for(int cntr=0; cntr<length; cntr++) {
		if(cntr == pivot) {
			log=log+"{<"+to_string(currentAmt[cntr])+">}";
		} else {
			log=log+"["+to_string(currentAmt[cntr])+"]";
		}
	}
	log=log+"\n\n\n";
	if(kVal==pivot-firstSelect+1) {
		log=log+"kth smallest number is: "+to_string(currentAmt[pivot]);
		fout.open("log.txt");
		fout<<log<<endl;
		fout.close();
	}
}
#endif
