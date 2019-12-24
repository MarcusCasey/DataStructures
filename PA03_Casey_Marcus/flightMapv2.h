/**
 * Marcus Casey
 * CS302
 **/
#include <string>
#include "Stack.cpp"
#include "City.h"

using namespace std;

class flightMapv2 {
	public:
		flightMapv2(City* sentCityHead, int sentNumCities);
		~flightMapv2();
		
		bool determinePath (City* originCity, City* destinationCity, ofstream* outputFilePA04); 
		void makeVisited (City* sentCity);
		void resetAllVisited (); 
		void resetAllVisited (vector<City *> *sentVector);
		City* gNextCity (City* fromCity);

	private:
		City* headCity;
		int citiesNum;
};
