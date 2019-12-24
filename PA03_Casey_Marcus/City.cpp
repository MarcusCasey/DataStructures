/**
 * Marcus Casey
 * CS302
 **/
#include "City.h"
using namespace std;

City::City () {
	cityNameCurrent = "NO ASSIGNED CITY";
	hasVisited = false;
	destinations = 0;
}

City::City (string name) {
	cityNameCurrent = name;
	hasVisited = false;
	destinations = 0;
}

City::~City () {
}

City* City::gDestination (string name) {
	unsigned int position = 0;
	while (destinationNames[position] != name) {
		position++;
	}
	return destinationPointers[position]; 
}

void City::outputCityToLog (ofstream* outputFilePA04) {
	(*outputFilePA04) << cityNameCurrent << " has the destinations: {";
	if (destinations <= 0) {
		(*outputFilePA04) << "(No Destinations)";
	} else {
		for (unsigned int i = 0; i < destinationNames.size(); i++) {
			if (i == destinationNames.size() - 1) {
				(*outputFilePA04) << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i];
			} else {
				(*outputFilePA04) << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i] << ",";
			}
		}
	}
	(*outputFilePA04) << "}" << endl;
	return;
}
City* City::gUntouredDestination () {
	for (int i = 0; i < destinations; i++) {
		if (!(*(destinationPointers[i])).isVisited()) {
			return destinationPointers[i];
		}
	}
	return NULL;
}

string City::gCityName () {
	return cityNameCurrent;
}

int City::gDestinationNum () {
	return destinations;
}

vector<City *> City::GetDestinationPointers () {
	return destinationPointers;
}

bool City::isDestination (string name) {
	for (unsigned int i = 0; i < destinationNames.size(); i++) {
		if (destinationNames[i] == name) {
			return true; 
		}
	}
	return false; 
}

void City::outputCity () {
	cout << cityNameCurrent << " has the destinations: {";
	if (destinations <= 0) {
		cout << "(No Destinations)";
	} else {
		for (unsigned int i = 0; i < destinationNames.size(); i++)	{
			if (i == destinationNames.size() - 1) {
				cout << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i];
			} else {
				cout << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i] << ",";
			}
		}
	}
	cout << "}" << endl;
	return;
}

void City::sVisitedState (bool state) {
	hasVisited = state;
	return;
}

void City::sCityName (string name) {
	cityNameCurrent = name;
	return;
}

bool City::isVisited () {
	return hasVisited;
}

void City::combineDestination (string name, City* ptrLoc, int numFlight, int price) {
	for (unsigned int i = 0; i < destinationNames.size(); i++) {
		if (destinationNames[i] == name) {
			return; 
		}
	}
	destinationNames.push_back(name);
	destinationPointers.push_back(ptrLoc);
	flightNumbers.push_back(numFlight);
	flightCosts.push_back(price);
	destinations++;
	return;
}
int City::outputFlight (City* ptrLoc) {
	int destinationIndex = 0;
	string destinationName = (*ptrLoc).gCityName();
	int index = 0;
	for (index; index < destinations; index++) {
		if (destinationNames[index] == destinationName) {
			break;
		}
	}
	cout << "Flight #" << flightNumbers[index] << " from " << cityNameCurrent << " to " << destinationName;
	cout << "\tCost: $" << flightCosts[index] << endl;
	return flightCosts[index];
}
