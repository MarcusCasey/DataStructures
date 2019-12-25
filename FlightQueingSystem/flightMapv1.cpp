/**
 * Marcus Casey
 * CS302
 **/
#ifndef map_v1
#define map_v1
#include "flightMapv1.h"
using namespace std;

flightMapv1::flightMapv1 (City* sentCityHead, int sentNumCities) {
	headCity = sentCityHead;
	citiesNum = sentNumCities;
}

flightMapv1::~flightMapv1 () {
	headCity = NULL;
}

bool flightMapv1::determinePath (City* originCity, City* destinationCity, ofstream* outputFilePA04) {
	Stack<string> cityStack; 
	Stack<City *> cityPTRStack; 
	resetAllVisited();
	cityStack.push((*originCity).gCityName());
	cityPTRStack.push(originCity);
	makeVisited(originCity);
	City* topCity = cityPTRStack.peek();
	while (!cityStack.isEmpty() && topCity != destinationCity) {
		City* nextCity = gNextCity(topCity);
		if (nextCity == NULL) {
			cityStack.pop();
			cityPTRStack.pop();
		} else {
			cityStack.push((*nextCity).gCityName());
			cityPTRStack.push(nextCity);
			makeVisited(nextCity);
		}
		if (!cityStack.isEmpty()) {
			topCity = cityPTRStack.peek();
		}
	}
	cityStack.printFlightsToLog(outputFilePA04);
	bool finalBool = !cityPTRStack.isEmpty();
	if (!cityPTRStack.isEmpty()) {
		Stack<City *> reverseCityPTRStack;
		while (!cityPTRStack.isEmpty()) {
			reverseCityPTRStack.push(cityPTRStack.pop());
		}
		int totalCost = 0;
		while (!reverseCityPTRStack.isEmpty()) {
			City* currentCity = reverseCityPTRStack.pop();
			City* nextCity = reverseCityPTRStack.peek();
			if (nextCity != NULL) {
				totalCost += (*currentCity).outputFlight(nextCity);
			}
		}
		cout << "Total Cost: $" << totalCost << endl;
	} else {
		cout << "HPair does not fly from " << (*originCity).gCityName() << " to " << (*destinationCity).gCityName() << "." << endl;
	}
	return finalBool;
}

void flightMapv1::makeVisited (City* sentCity) {
	(*sentCity).sVisitedState(true);
	return;
}

void flightMapv1::resetAllVisited () {
	City* cityTrav = headCity;
	for (int i = 0; i < citiesNum; i++) {
		(*cityTrav).sVisitedState(false);
		cityTrav++;
	}
	cityTrav = NULL;
	return;
}

City* flightMapv1::gNextCity (City* fromCity) {
	return (*fromCity).gUntouredDestination();
}
#endif
