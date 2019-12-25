// CS 302
// Marcus Casey
// Project 5

#ifndef QUEUE_H
#define QUEUE_H
// some code from cs 202 queue assigenment
#include <iostream>
using namespace std;

class Queue;
struct Customer {
   Customer( const int timeArrival, const int timeTransaction, Customer* following );
   Customer* chain;
   int arrivalTime;
   int transactionTime;
};

class Queue {
   public:
      Queue();
      ~Queue();
      int frontTime();
      int frontTransactionTime();
      int getLength();
      bool push( const int timeArrival, const int timeDestination );
      bool pop();
      bool isEmpty();
   private:
      Customer* front;
      Customer* back;
};
#endif 
