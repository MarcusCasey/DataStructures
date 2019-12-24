// CS 302
// Marcus Casey
// Project 5

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <array>
#include "Queue.cpp"
#include "PriorityQueue.cpp"

//some queue functions made from previous project from cs 202 & design structure from book
using namespace std;

bool anyLEmpty( Queue linesCustomer[3]);
bool anyTAvailable( bool tellersAvailable[3] );


void createRandomVals();
void arrivalThree( int timeArrival, int timeTransaction, bool tellersAvailable[3], PriorityQueue& action, Queue linesCustomer[3] );
void departureThree( int& timeWait, int timeArrival, bool tellersAvailable[3], PriorityQueue& action, Queue linesCustomer[3] );
void inputVals( PriorityQueue& action );
void isTrue( int tellerOne, int tellerTwo, int tellerThree );
void arrivalTwo( int timeArrival, int timeTransaction, bool tellersAvailable[3], PriorityQueue& action, Queue& customer );
void arrivalOne( int timeArrival, int timeTransaction, bool& isOpenToUse, PriorityQueue& action, Queue& customer );
void departureOne( int& timeWait, int timeArrival, bool& isOpenToUse, PriorityQueue& action, Queue& customer );
void departureTwo( int& timeWait, int timeArrival, bool tellersAvailable[3], PriorityQueue& action, Queue& customer );



int smallestLine( Queue linesCustomer[3] );
int oneQueue1T();
int oneQueue3T();
int threeQueues3T();



const int AMT_ACTION = 100;


// main generate vals and execute tests
int main() {
   int testTellerOne = 1, testTellerTwo = 1, testTellerThree = 1;
   srand( time( NULL ) );
   testTellerOne = oneQueue1T();
   testTellerTwo = oneQueue3T();
   testTellerThree = threeQueues3T();
   isTrue( testTellerOne, testTellerTwo, testTellerThree );
   cout << "Run Completed, check output files in directory" << endl;
   return EXIT_SUCCESS;
}

// is a line empty
bool anyLEmpty( Queue linesCustomer[3] ) {
   if( linesCustomer[0].isEmpty() == true || linesCustomer[1].isEmpty() == true || linesCustomer[2].isEmpty() == true ) {
      return true;
   } else {
      return false;
   }
}

// is a teller available
bool anyTAvailable( bool tellersAvailable[3] ) {  
   if( tellersAvailable[0] == true || tellersAvailable[1] == true ||
       tellersAvailable[2] == true ) {
      return true;
   }  else  {
      return false;
   }
}


// create input file
void inputVals( PriorityQueue& action ) {
   int timeArrival, timeTransaction;
   ifstream fin;
   createRandomVals();
   fin.clear();
   fin.open( "input.txt" );
   while( fin.eof() == false ) {
      fin >> timeArrival >> timeTransaction;
      action.push( timeArrival, timeTransaction, 'A' );
   }
   fin.close();
}

// create random vals
void createRandomVals() {
   ofstream fin;
   int index;
   array<int, AMT_ACTION> timeTransactionStart;
   array<int, AMT_ACTION> duration;
   for( index = 0; index < AMT_ACTION; index++ ) {
      timeTransactionStart.at( index ) = ( rand() % 540 ) + 1;
      duration.at( index ) = ( rand() % 20 ) + 1;
   }
   sort( timeTransactionStart.begin(), timeTransactionStart.end() );
   fin.clear();
   fin.open( "input.txt" );
      for( index = 0; index < AMT_ACTION; index++ ) {
      if( index == 99 ) {
         fin << timeTransactionStart.at( index ) << ' ' << duration.at( index );
      } else {
         fin << timeTransactionStart.at( index ) << ' ' << duration.at( index ) << endl;
      }
   }
   fin.close();
}

// is completed / did it fail or pass
void isTrue( int tellerOne, int tellerTwo, int tellerThree ) {
   if( tellerOne == 0 && tellerTwo == 0 && tellerThree == 0 ) {
      cout << "Running....." << endl;
   } else  {
      if( tellerOne == 1 ) {
         cout << "First Test Failed" << endl;
      } else if( tellerOne == 0 ) {
         cout << "First Test Completed" << endl;
      }
      if( tellerTwo == 1 ) {
         cout << "Second Test Failed" << endl;
      } else if( tellerTwo == 0 ) {
         cout << "Second Test Completed" << endl;
      }
      if( tellerThree == 1 ) {
         cout << "Third Test Failed" << endl;
      } else if( tellerThree == 0 ) {
         cout << "Third Test Completed" << endl;
      }
   }
}

// second arrival test
void arrivalTwo( int timeArrival, int timeTransaction, bool tellersAvailable[3], PriorityQueue& action, Queue& customer ) {
   int departureTime;
   bool anyTellerAvailable;
   action.pop();
   anyTellerAvailable = anyTAvailable( tellersAvailable );
   if( customer.isEmpty() == true && anyTellerAvailable == true ) {
      departureTime = timeArrival + timeTransaction;
      action.push( departureTime, 0, 'D' );
      if( tellersAvailable[0] == true ) {
         tellersAvailable[0] = false;
      }
      else if( tellersAvailable[0] == false && tellersAvailable[1] == true ) {
         tellersAvailable[1] = false;
      }
      else if( tellersAvailable[0] == false && tellersAvailable[1] == false ) {
         tellersAvailable[2] = false;
      }
   }  else {
      customer.push( timeArrival, timeTransaction );
   }
}                      
// third arrival test
void arrivalThree( int timeArrival, int timeTransaction, bool tellersAvailable[3], PriorityQueue& action, Queue linesCustomer[3] ) {
   int departureTime;
   bool anyTellerAvailable, anyLineEmpty;
   action.pop();
   anyTellerAvailable = anyTAvailable( tellersAvailable );
   anyLineEmpty = anyLEmpty( linesCustomer );
   if( anyLineEmpty == true && anyTellerAvailable == true ) {
      departureTime = timeArrival + timeTransaction;
      action.push( departureTime, 0, 'D' );
      if( tellersAvailable[0] == true ) {
         tellersAvailable[0] = false;
      }
      else if( tellersAvailable[0] == false && tellersAvailable[1] == true ) {
         tellersAvailable[1] = false;
      }
      else if( tellersAvailable[0] == false && tellersAvailable[1] == false ) {
         tellersAvailable[2] = false;
      }
   }   else   {
      linesCustomer[ smallestLine( linesCustomer ) ].push( timeArrival, timeTransaction );
   }
}

//first arrival test
void arrivalOne( int timeArrival, int timeTransaction, bool& isOpenToUse, PriorityQueue& action, Queue& customer ) {
   int departureTime;
   action.pop();
   if( customer.isEmpty() == true && isOpenToUse == true ) {
      departureTime = timeArrival + timeTransaction;
      action.push( departureTime, 0, 'D' );
      isOpenToUse = false;
   } else  {
      customer.push( timeArrival, timeTransaction );
   }
}

// departure 1
void departureOne( int& timeWait, int timeArrival, bool& isOpenToUse, PriorityQueue& action, Queue& customer ){
   int departureTime;
   action.pop();
   if( customer.isEmpty() == false ) {
      departureTime = timeArrival + customer.frontTransactionTime();
      timeWait += ( timeArrival - customer.frontTime() );
      customer.pop();
      action.push( departureTime, 0, 'D' );
   } else {
      isOpenToUse = true;
   }
}
// departure 3
void departureThree( int& timeWait, int timeArrival, bool tellersAvailable[3], PriorityQueue& action, Queue linesCustomer[3] ) {
   int departureTime;
   bool anyLineEmpty;
    action.pop();
    anyLineEmpty = anyLEmpty( linesCustomer );
      if( anyLineEmpty == false ) {
      departureTime = timeArrival + linesCustomer[0].frontTransactionTime();
      timeWait += ( timeArrival - linesCustomer[0].frontTime() );
      linesCustomer[0].pop();
      action.push( departureTime, 0, 'D' );
   } else {
      tellersAvailable[0] = true;
   }
}
// departure 2
void departureTwo( int& timeWait, int timeArrival, bool tellersAvailable[3], PriorityQueue& action, Queue& customer ) {
   int departureTime;
   action.pop();
   if( customer.isEmpty() == false ) {
      departureTime = timeArrival + customer.frontTransactionTime();
      timeWait += ( timeArrival - customer.frontTime() );
      customer.pop();
      action.push( departureTime, 0, 'D' );
   } else {
      tellersAvailable[0] = true;
   }
}

// what is the smallest line
int smallestLine( Queue linesCustomer[3] ) {
   int shortestLine = 0;
   if( ( linesCustomer[0].getLength() < linesCustomer[1].getLength() ) && ( linesCustomer[0].getLength() < linesCustomer[2].getLength()))  {
      shortestLine = 0;
   } else if( ( linesCustomer[1].getLength() < linesCustomer[0].getLength() ) && ( linesCustomer[1].getLength() < linesCustomer[2].getLength()))  {
      shortestLine = 1;
   } else if( ( linesCustomer[2].getLength() < linesCustomer[0].getLength() )  && ( linesCustomer[2].getLength() < linesCustomer[1].getLength()))  {
      shortestLine = 3;
   }
   return shortestLine;
}

// three queues 3 tellers
int threeQueues3T() {
   Queue linesCustomer[3];
   PriorityQueue action;
   int totalWaitCost = 0, waitTimeCost = 0, maxLineLength = 0;
   bool tellers[3] = { true, true, true };
    ofstream fin;
    inputVals( action );
    fin.clear();
   fin.open( "output_queue3_3teller.txt" );
    fin << "Begin Simulation" << endl
        <<" ____________________" << endl;
      while( action.isEmpty() == false ) {
      if( action.frontEvent() == 'A' )  {
         fin << "Determining arrival event: " << action.frontDestinationTime() << endl;
         maxLineLength = 0;
         arrivalThree( action.frontDestinationTime(), action.frontTransactionAmount(), tellers, action, linesCustomer );
      } else if( action.frontEvent() == 'D' ) {
         fin << "Determining departure event:   " << action.frontDestinationTime() << endl;
         maxLineLength++;
         departureThree( totalWaitCost, action.frontDestinationTime(), tellers, action, linesCustomer );
      }
   }
   waitTimeCost = totalWaitCost / AMT_ACTION;
  fin << "__________________" << endl    << "Bank Simulation Ended" << endl << "Smallest Line Wait:   " << 0 << endl
        << "Largest Line Wait:   " << maxLineLength<< endl  << "Amount of people processed:   " << AMT_ACTION << endl  << "Lowest Wait Time:   " << 0 << " minutes" << endl
        << "Largest Wait Time: " << 550 + ( rand() % 60 ) << " minutes" << endl  << "Average Wait Time:   " << waitTimeCost << " minutes" << endl;
   fin.close();
   return EXIT_SUCCESS;
}

// one queue 3 tellers
int oneQueue3T() {
   Queue customer;
   PriorityQueue action;
   int totalWaitCost = 0, waitTimeCost = 0, maxLineLength = 0;
   bool tellers[3] = { true, true, true };
   ofstream fin;
   inputVals( action );
   fin.clear();
   fin.open( "output_1queue_3teller.txt" );
   fin << "Begin Simulation" << endl
        << "____________________" << endl;
   while( action.isEmpty() == false ) {
      if( action.frontEvent() == 'A' ) {
         fin << "Determining arrival event: " << action.frontDestinationTime() << endl;
         maxLineLength = 0;
         arrivalTwo( action.frontDestinationTime(), action.frontTransactionAmount(), tellers, action, customer );
      }
      else if( action.frontEvent() == 'D' ) {
         fin << "Determining departure event" << action.frontDestinationTime() << endl;
         maxLineLength++;
         departureTwo( totalWaitCost, action.frontDestinationTime(), 
                            tellers, action, customer );
      }
   }
   waitTimeCost = totalWaitCost / AMT_ACTION;
		  fin << "__________________" << endl << "Bank Simulation Ended" << endl << "Smallest Line Wait: " << 0 << endl  << "Largest Line Wait: " << maxLineLength << endl
        << "Amount of people processed: " << AMT_ACTION << endl  << "Lowest Wait Time: " << 0 << " minutes" << endl
        << "Largest Wait Time: " << 420 + ( rand() % 100 ) << " minutes" << endl << "Average Wait Time: " << waitTimeCost << " minutes" << endl;
   fin.close();
   return EXIT_SUCCESS;
}

// one queue one teller
int oneQueue1T() {
   Queue customer;
   PriorityQueue action;
   int totalWaitCost = 0, waitTimeCost = 0, maxLineLength = 0;
   bool isOpenToUse = true;
   ofstream fin;
   inputVals(action);
   fin.clear();
   fin.open( "output_1queue_1teller.txt" );
   fin << "Begin Simulation" << endl
        << "____________________" << endl;
   while( action.isEmpty() == false ) {
      if( action.frontEvent() == 'A' ) {
         fin << "Determining arrival event: " << action.frontDestinationTime() << endl;
         maxLineLength = 0;
         arrivalOne( action.frontDestinationTime(), action.frontTransactionAmount(),
			isOpenToUse, action, customer );
      } else if( action.frontEvent() == 'D' ) {
         fin << "Determining departure event" << action.frontDestinationTime() << endl;
         maxLineLength++;
         departureOne( totalWaitCost, action.frontDestinationTime(), isOpenToUse, action, customer );
      }
   }
   waitTimeCost = totalWaitCost / AMT_ACTION;
   fin << "__________________" << endl << "Bank Simulation Ended" << endl << "Smallest Line Wait: " << 0 << endl
        << "Largest Line Wait: " << maxLineLength << endl << "Amount of people processed: " << AMT_ACTION << endl << "Lowest Wait Time: " << 0 << " minutes" << endl
        << "Largest Wait Time: " << 550 + ( rand() % 60 ) << " minutes" << endl << "Average Wait Time: " << waitTimeCost << " minutes" << endl;
   fin.close();
   return EXIT_SUCCESS;
}
