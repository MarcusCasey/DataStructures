// CS 302
// Marcus Casey
// Project 5

#include <cstdlib>
#include <iostream>
#include "Queue.h"
// some code from cs 202 queue assignent
using namespace std;

Customer::Customer( const int timeArrival, const int timeTransaction, Customer* following ) {
   arrivalTime = timeArrival;
   transactionTime = timeTransaction;
   chain = following;
}

Queue::Queue() {
   front = NULL;
   back = NULL;
}

Queue::~Queue() {
   while(front != NULL) {
      back = front->chain;
      delete front;
      front = back;
   }
}

int Queue::frontTime() {
   return front->arrivalTime;
}

int Queue::getLength() {
   Customer* var1 = front;
   int length = 0;
   while( var1 != NULL ){
      length++;
      var1 = var1->chain;
   }
   return length;   
}

int Queue::frontTransactionTime() {
   return front->transactionTime;
}

bool Queue::pop() {
   if(front == NULL)  {
      return false;
   } else {
      Customer* var1 = front;
      front = front->chain;
      var1->chain = NULL;
      delete var1;
      var1 = NULL;

      if( front == NULL )  {
         back = NULL;
      }
      return true;
   }
   return false;
}

bool Queue::isEmpty() {
   if( front == NULL )  {
      return true;
   } else {      
   return false;
   }
}

bool Queue::push(const int timeArrival, const int timeDestination){
   	if( back == NULL ) {
      back = new Customer(timeArrival, timeDestination, NULL);
      front = back;
      return true;
   } else {
      back->chain = new Customer(timeArrival, timeDestination, NULL);
      back = back->chain;
      return true;
   }
   return false;
}
