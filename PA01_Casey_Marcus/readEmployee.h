/**
 * Marcus Casey
 * CS302
 **/

// Header Guard
#ifndef  READEMPLOYEE_H
#define  READEMPLOYEE_H
// import libraries
#include <string>
#include <iostream>

using namespace std;

class Employee {

public: 
// constructor / destructor
	Employee();
	~Employee();

	// functions
	void sortByID();
	void sortByAge();
	void sortByFName();
	void sortByLName();
	void sortByGender();
	void printEmployee();
private:
	int employeeID;
	int employeeAge;
	string firstName;
	string lastName;
	string gender;
};
#endif
