/**
 * Marcus Casey
 * CS302
 **/
#include <string>
#include "Stack.cpp"
#include "City.h"
using namespace std;

class flightMapv1 {
	public:
		flightMapv1(City* sentCityHead, int sentNumCities);
		~flightMapv1();
		City* gNextCity (City* fromCity);
		bool determinePath (City* originCity, City* destinationCity, ofstream* logFile);
		void makeVisited (City* sentCity);
		void resetAllVisited ();

	private:
		City* headCity;
		int citiesNum;
};
