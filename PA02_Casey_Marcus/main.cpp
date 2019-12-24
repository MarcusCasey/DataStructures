//  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <fstream>
#include "kSmall.h"

int main(){
	//Declerations (insert as needed)
	int kSmall_pos=0;	//For User Input
	int kSmall_val=0;	//Populate using your algorithm implementation
	int pivot; 		//Unused, functionality in header file.
	string fileName;        //String fileName
	kSmall getKSmall; 	//create new object getKSmall
	//User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value:";
	std::cin>>kSmall_pos;
	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	std::cout<<"Enter the file name: ";
	std::cin>> fileName;
	int size = getKSmall.analyzeArr(fileName);
	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
	kSmall_val = getKSmall.findKth(kSmall_pos,0,size-1, size);
	//Log file output (insert) - preferred in .txt format according to instructions posted on assignment page
	cout << "Created Output File: log.txt"<< endl;
	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val <<std::endl;
}
