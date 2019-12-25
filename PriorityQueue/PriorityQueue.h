// CS 302
// Marcus Casey
// Project 5

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
//some code from cs 202 p queue assignemtn
using namespace std;

class PriorityQueue;

struct Event{
   Event( const int firstAs, const int item, const char actionEvent, Event* following );
   char actionEvent;
   int timeDestination;
   int timeTransaction;
   Event* chain;
};

class PriorityQueue {
   public:
      PriorityQueue();
      ~PriorityQueue();
      int frontDestinationTime();
      int frontTransactionAmount();
      char frontEvent();
      bool push( const int priorityOne, const int data, const char type );
      bool pop();
      bool isEmpty();
   private:
      Event* back;
      Event* front;
};
#endif 
