/**
 * Marcus Casey
 * CS302
 **/
// import dependancies
#include "readEmployee.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
// first open  file by assigning an fstream
// once file is opened load in file to array
// once file has been loaded to array call first sort desired
// this can be accomplished through a key command 1-5 to sort as desired
// then call printEmlpoyee() which would provide the array
// close file
// end program
return 0;
}

// in a real program it would be more useful to store functions in "functions.cpp or something similar
// constructor, anything needed to be initialized or created would be included 
Employee::Employee(){
// potentially assigning size of employees, or a cursor navigating through data file
}
// destructor, reinitializing, deleting data would be useful to include in this fnc
Employee::~Employee(){
// deleting data stored in an array, or in variables that were used to sort in the fnc
}
// sort employee id, simple array sort based on read in data
void Employee::sortByID(){
// to sort by the id a simple array sort would be used to compare numbers to each other and store appropriately. 
}
// potentially useful method to sort employee by age if data provided.
void Employee::sortByAge(){
// done similar to sortbyid in comparing them and storing in an array and sorting. 
}
// grab first name of employee provided by data
void Employee::sortByFName(){
// compare based on first value of first name using str.compare. simple function
}
// grab last name of employee
void Employee::sortByLName(){
// identical to first name, str.compare
}
// sort by gender if provided by data. almost identical to last name & first name
void Employee::sortByGender(){
// sort by gender first char using str.compare.
}
// function to print what is currently stored in array
void Employee::printEmployee(){
// print sorted employee data based on what sort was used. 
}

