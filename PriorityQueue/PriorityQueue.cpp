// CS 302
// Marcus Casey
// Project 5
#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"

using namespace std;
// some code from CS 202 queue project
Event::Event( const int firstAs, const int item, const char type, Event* following ) {
   timeDestination = firstAs;
   timeTransaction = item;
   actionEvent = type;
   chain = following;
}

PriorityQueue::PriorityQueue() {
   front = NULL;
   back = NULL;
}

PriorityQueue::~PriorityQueue() {
   while( front != NULL ) {
      back = front->chain;
      delete front;
      front = back;
   }
}

int PriorityQueue::frontDestinationTime() {
   return front->timeDestination;
}

int PriorityQueue::frontTransactionAmount() {
   return front->timeTransaction;
}

char PriorityQueue::frontEvent() {
   return front->actionEvent;

}
bool PriorityQueue::push(const int priorityOne, const int item, const char type) {
   Event* var1 = new Event(priorityOne, item, type, NULL);
   if(front == NULL || var1->timeDestination < front->timeDestination) {
      var1->chain = front;
      front = var1;
      return true;
   } else {
      Event* var2 = front;
      while( var2->chain != NULL && var2->chain->timeDestination <= var1->timeDestination ) {
         var2 = var2->chain;
      }
      var1->chain = var2->chain;
      var2->chain = var1;
      return true;
   }
   return false;
}

bool PriorityQueue::pop() {
   if(front == NULL) {
      return false;
   } else {
      Event* temp = front;
      front = front->chain;
      temp->chain = NULL;
      delete temp;
      temp = NULL;
      if(front == NULL) {
         back = NULL;
      }
      return true;
   }
   return false;
}

bool PriorityQueue::isEmpty() {
   if(front == NULL) {
      return true;
   }  else  {
      return false;
   }
}
