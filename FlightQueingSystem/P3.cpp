/**
 * Marcus Casey
 * CS302
 **/
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include "flightMapv1.h"
#include "flightMapv2.h"
// no std::
using namespace std;

int gDataAmount (ifstream *sentFile);
void readLine (string sentLine, string* tabCity, string* altCity);
void readLine (string sentLine, string* tabCity, string* altCity, int* flightNum, int* price);
int dCityIndex (string name, City* cityArray, int cityCount);
bool isCorrectCity (string name, City* cities, int citiesNum);
ofstream outputFilePA04;

int main() {
	ifstream cityFile;
	ifstream flightFile;
	ifstream requestFile;

	outputFilePA04.open("logoutput.txt");
	cityFile.open("cityFile.txt");
	outputFilePA04 << "Open City File" << endl;
	int cityCount = gDataAmount(&cityFile);
	outputFilePA04 << "count cities" << endl;
	City cities[cityCount];
	cityFile.open("cityFile.txt");
	for (int i = 0; i < cityCount; i++) {
		string readString;
		getline(cityFile, readString);
		cities[i].sCityName(readString);
	}
	for (int i = 0; i < cityCount; i++) {
		cities[i].outputCityToLog(&outputFilePA04);
	}
	cityFile.close();
	flightFile.open("flightFile.txt");
	int flightCount = gDataAmount(&flightFile);
	if (flightCount <= 0) {
		cout << "Empty or incorrect flight file name" << endl;
		outputFilePA04 << "Empty or incorrect flight file name" << endl;
		return 0;
	}
	flightFile.open("flightFile.txt");
	for (int i = 0; i < flightCount; i++)	{
		string readString;
		getline(flightFile, readString);
		string fromCity;
		string toCity;
		int numFlight;
		int price;
		outputFilePA04 << "Reading : \"" << readString << "\"" << endl;
		readLine(readString, &fromCity, &toCity, &numFlight, &price);
		outputFilePA04 << "Read from: " << fromCity << " Read to: " << toCity << endl;
		int fromCityIndex = dCityIndex(fromCity, cities, cityCount);
		int toCityIndex = dCityIndex(toCity, cities, cityCount);
		if (fromCityIndex >= 555555 || toCityIndex >= 555555) {
			cout << "Too many cities." << endl;
			outputFilePA04 << "Too many cities." << endl;
			return 0;
		}
		City* toCityPtr = cities;
		for (int i = 0; i < toCityIndex; i++) {
			toCityPtr++;
		}
		cities[fromCityIndex].combineDestination(toCity, toCityPtr, numFlight, price);
	}

///////////////////////////////// uncomment out for different version ////////////////////////////////////	
	flightMapv1 map(cities, cityCount);
	//flightMapv2 map(cities, cityCount);

	requestFile.open("requestFile.txt");
	outputFilePA04 << "Opened Request File:" << endl;
	int requestCount = gDataAmount(&requestFile);
	if (requestCount <= 0) {
		cout << "Empty or incorrect flight file name" << endl;
		outputFilePA04 << "Empty or incorrect flight file name" << endl;
		return 0;
	}
	requestFile.open("requestFile.txt");
///////////////////////////////// Depending on City's in request file append int i by 1 per line added ////////////////////////////////////		
	for (int i = 1; i < requestCount; i++) {
		string readString;
		getline(requestFile, readString);
		string fromCity;
		string toCity;
		outputFilePA04 << "Reading \"" << readString << "\"" << endl;
		readLine(readString, &fromCity, &toCity);
		outputFilePA04 << "Read from: " << fromCity << " Read to: " << toCity << endl;
		cout << "Determining to depart from " << fromCity << " to " << toCity << ".." << endl;
		if (!isCorrectCity(fromCity, cities, cityCount) && !isCorrectCity(toCity, cities, cityCount)) {
			cout << "HPair doesn't fly " << fromCity << " & " << toCity << ".." << endl << endl;
			outputFilePA04 << "HPair doesn't fly " << fromCity << " & " << toCity << ".."<< endl;
			continue;
		} else if (!isCorrectCity(fromCity, cities, cityCount)) {
			cout << "HPair doesn't fly " << fromCity << ".." << endl << endl;
			outputFilePA04 << "HPair doesn't fly " << fromCity << ".."<< endl;
			continue;
		} else if (!isCorrectCity(toCity, cities, cityCount)) {
			cout << "HPair doesn't fly " << toCity << ".." << endl << endl;
			outputFilePA04 << "HPair doesn't fly " << toCity << ".."<< endl;
			continue;
		}
		int fromCityIndex = dCityIndex(fromCity, cities, cityCount);
		int toCityIndex = dCityIndex(toCity, cities, cityCount);
		outputFilePA04 << "next is " << fromCity << "(" << fromCityIndex << ") to " << toCity << "(" << toCityIndex << ")" << endl;
		if (fromCityIndex >= 555555 || toCityIndex >= 555555) {
			cout << "Empty or incorrect flight file name" << endl;
			return 0;
		}
		if (map.determinePath (&cities[fromCityIndex], &cities[toCityIndex], &outputFilePA04)) {
			outputFilePA04 << "Found route" << endl;
		} else {
			outputFilePA04 << "Cannot Find route" << endl;
		}
		cout << endl;
	}
	outputFilePA04 << "Good Run, Ending" << endl;
	outputFilePA04.close();
	return 0;
}

int gDataAmount (ifstream *sentFile) {
	int count = 0;
	bool continueRead = true;
	while (continueRead) {
		string temp;
		getline(*sentFile, temp);
		if ((*sentFile).eof()) {
			continueRead = false;
		} else {
			count++;
		}
	}
	(*sentFile).close();
	return count + 1;
}

void readLine (string sentLine, string* tabCity, string* altCity) {
	char* leftCityChars = new char[15]; 
	char* rightCityChars = new char[15];
	char* charTrav;
	charTrav = leftCityChars;
	int charIndex = 0;
	for (charIndex = 0; charIndex < 15; charIndex++) {
		char readChar = sentLine.at(charIndex);
		if (readChar == ',' || readChar < 65 && readChar != ' ') {
			*charTrav = '\0';
			break;
		} else {
			*charTrav = readChar;
			charTrav++;
		}
	}
	charTrav = rightCityChars;
	charIndex++; 
	charIndex++;
	for (charIndex; charIndex < 31 && charIndex < sentLine.length(); charIndex++) {
		char readChar = sentLine.at(charIndex);
		if ((readChar == ',' || readChar < 65 || readChar == '\n') && readChar != ' ') {
			*charTrav = '\0';
			break;
		} else if ((readChar >= 65 && readChar <= 90) || (readChar >= 97 && readChar <= 122) || readChar == ' ') {
			*charTrav = readChar;
		   	 charTrav++;
		} else {
			*charTrav = '\0';
			break;
		}
	}
	*charTrav = '\0';
	*tabCity = leftCityChars;
	*altCity = rightCityChars;
	charTrav = NULL;
	delete[] leftCityChars;
	leftCityChars = NULL;
	delete[] rightCityChars;
	rightCityChars = NULL;
	return;
}

bool isCorrectCity (string name, City* cities, int citiesNum) {
	bool isCity = false;
	City* cityTrav = cities;
	for (int i = 0; i < citiesNum; i++) {
		if ((*cityTrav).gCityName() == name) {
			isCity = true;
			break;
		}
		cityTrav++;
	}
	cityTrav = NULL;
	return isCity;
}

void readLine (string sentLine, string* tabCity, string* altCity, int* flightNum, int* price) {
	char* leftCityChars = new char[15];
	char* rightCityChars = new char[15];
	char* charTrav;
	charTrav = leftCityChars;
	int charIndex = 0;
	for (charIndex = 0; charIndex < 15; charIndex++) {
		char readChar = sentLine.at(charIndex);
		if (readChar == ',' || readChar < 65 && readChar != ' ') {
			*charTrav = '\0';
			break;
		} else {
			*charTrav = readChar;
			charTrav++;
		}
	}
	charTrav = rightCityChars;
	charIndex++;
	charIndex++;
	for (charIndex; charIndex < 31 && charIndex < sentLine.length(); charIndex++) {
		char readChar = sentLine.at(charIndex);
		if ((readChar == ',' || readChar < 65 || readChar == '\n') && readChar != ' ') {
			*charTrav = '\0';
			break;
		} else if ((readChar >= 65 && readChar <= 90) || (readChar >= 97 && readChar <= 122) || readChar == ' ') {
			*charTrav = readChar;
			charTrav++;
		} else {
			*charTrav = '\0';
			break;
		}
	}
	*charTrav = '\0';
	bool hasReadNumber = false;
	Stack<int> intStack;
	for (charIndex; charIndex < sentLine.length(); charIndex++) {
		char readChar = sentLine.at(charIndex);

		if ((readChar == ' ' || readChar == '\t') && !hasReadNumber) {
			continue;
		} else if (readChar >= '0' && readChar <= '9') {
			int convertedChar = (int) readChar - '0';
			intStack.push(convertedChar);
			hasReadNumber = true;
		} else if ((readChar == ' ' || readChar == '\t') && hasReadNumber) {
			break;
		}
	}
	int readFlightNumber = 0;
	for (int i = 0; !intStack.isEmpty(); i++) {
		int value = intStack.pop() * (int) pow(10, i);
	}
	hasReadNumber = false;
	intStack.clear();
	for (charIndex; charIndex < sentLine.length(); charIndex++) {
		char readChar = sentLine.at(charIndex);
		if ((readChar == ' ' || readChar == '\t') && !hasReadNumber) {
			continue;
		} else if (readChar >= '0' && readChar <= '9') {
			int convertedChar = (int) readChar - '0';
			intStack.push(convertedChar);
			hasReadNumber = true;
		} else if ((readChar == ' ' || readChar == '\t') && hasReadNumber) {
			break;
		}
	}
	int readPrice = 0;
	for (int i = 0; !intStack.isEmpty(); i++) {
		int value = intStack.pop() * (int) pow(10, i);
		readPrice += value;
	}
	*tabCity = leftCityChars;
	*altCity = rightCityChars;
	*price = readPrice;
	*flightNum = readFlightNumber;
	charTrav = NULL;
	delete[] leftCityChars;
	leftCityChars = NULL;
	delete[] rightCityChars;
	rightCityChars = NULL;
	return;
}

int dCityIndex (string name, City* cityArray, int cityCount) {
	City* cityTrav = cityArray;
	for (int i = 0; i < cityCount; i++) {
		if ((*cityTrav).gCityName() == name) {
			return i;
		} else {
			cityTrav++;
		}
	}
	return 50000;
}
