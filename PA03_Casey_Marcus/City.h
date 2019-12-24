/**
 * Marcus Casey
 * CS302
 **/
#include <iostream>
#include <fstream>
#include <vector>
#ifndef city_class
#define city_class

using namespace std;

class City {
	public:
		City();
		City(string name);
		~City();

		void sVisitedState(bool state);
		void outputCityToLog(ofstream* outputFilePA04);
		void sCityName(string name);
		void outputCity();
		void combineDestination(string name, City* ptrLoc, int numFlight, int price);
		bool isDestination(string name);
		bool isVisited();
		City* gDestination(string name);	
		City* gUntouredDestination();	
		string gCityName();
		int gDestinationNum ();
		int outputFlight(City* ptrLoc);
		vector<City *> GetDestinationPointers();

	private:
		bool hasVisited;
		int destinations;
		vector<string> destinationNames; 
		vector<City *> destinationPointers; 
		vector<int> flightNumbers;
		vector<int> flightCosts;
		string cityNameCurrent;
};
#endif
