// Marcus Casey
// CS 302
// Project 6

// import
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "BinarySearchTree.cpp"

using namespace std;
// fnc header
int createUniqueOverlap (int* dest, int* dataC, int amtMain, int amtSecond, int overEach);
void executeTraversals (BinarySearchTree<int>* sentLeaf);
void createRandVals (int* dest, int amt);
// main
int main() {
// vars
	int minimumOverEach = 3;
	int amt1 = 100;
	int amt2 = 10;
	BinarySearchTree<int> firstTree;
	BinarySearchTree<int> secondTree;
	int* firstVal = new int[amt1];
	int* secondVal = new int[amt2];
	srand(time(0));
// begin testing process
	cout << "Creating random numbers." << endl;
	cout << "Creating unique vals" << endl;
	createRandVals(firstVal, amt1);
	cout << "Creating overlap values ";
	cout << createUniqueOverlap(secondVal, firstVal, amt1, amt2, minimumOverEach);
	cout << "Over Each." << endl << "Done" << endl;
	for (int k = 0; k < amt1; k++) {
		firstTree.Sum(*(firstVal + k));
	}
	for (int k = 0; k < amt2; k++) {
		secondTree.Sum(*(secondVal + k));
	}
	cout << endl << "Indorder Traversal For Main Tree " << endl;
	firstTree.executeTraversals(1);
	cout << endl << endl << "Tree Height: " << firstTree.getSize();
	cout << endl << endl << "Traversals on Overlap Tree: " << endl;
	executeTraversals(&secondTree);
	cout << endl << "Deleting overlap vals" << endl;
	for (int i = 0; i < amt2; i++) {
		if (firstTree.deleteThis(*(secondVal + i))) {
			cout << "Deleted " << *(secondVal + i) << endl;
		}
	}
	cout << endl << "Inorder traversal for the main tree: " << endl;
	firstTree.executeTraversals(1);
	cout << endl << endl << "Tree Height: " << firstTree.getSize();
	cout << endl << "Amount of nodes in main tree " << firstTree.getNodeAmount() << endl;
	cout << endl << "Clearing out trees" << endl;
	cout << "Before clearing the main tree is ";
	if (firstTree.isEmpty()) {
		cout << "Empty" << endl;
	} else {
		cout << "Not Empty" << endl;
	}
	cout << "Before clearing the secondary tree is ";
	if (secondTree.isEmpty()) {
		cout << "Empty" << endl;
	} else {
		cout << "Not empty" << endl;
	}
	firstTree.clearTree();
	secondTree.clearTree();
	cout << "After clearing the main tree is";
	if (firstTree.isEmpty()) {
		cout << "Empty" << endl;
	} else {
		cout << "Not Empty" << endl;
	}
	cout << "After clearing the secondary tree is ";
	if (secondTree.isEmpty()) {
		cout << "Empty" << endl;
	} else {
		cout << "not empty" << endl;
	}
	delete[] firstVal;
	delete[] secondVal;
	return 0;
}
// run traversals
void executeTraversals (BinarySearchTree<int>* sentLeaf) {
	cout << "Preorder Traversal: " << endl;
	(*sentLeaf).executeTraversals(0);
	cout << endl << endl;
	cout << "Inorder Traversal" << endl;
	(*sentLeaf).executeTraversals(1);
	cout << endl << endl;
	cout << "Postorder Traversal" << endl;
	(*sentLeaf).executeTraversals(2);
	cout << endl << endl;
	cout << "Tree height: " << (*sentLeaf).getSize() << endl;
	return;
}
// create random to sort through
void createRandVals (int* dest, int amt) {
	bool* occurs = new bool[amt];
	for (int i = 0; i < amt; i++) {
		*(occurs + i) = false;
	}
	for (int i = 0; i < amt; i++) {
		bool unique = false;
		while (!unique) {
			int tempVal = rand() % 200;
			if (*(occurs + tempVal) == true) {
				unique = false;
			} else {
				*(occurs + tempVal) = true;
				*(dest + i) = tempVal;
				unique = true;
			}
		}
	}
	return;
}
// create uniques with overlap
int createUniqueOverlap (int* dest, int* dataC, int amtMain, int amtSecond, int overEach) {
	int overlapCount = 0;
	while (overlapCount < overEach) {
		createRandVals(dest, amtSecond);
		overlapCount = 0;
		for (int i = 0; i < amtSecond; i++) {
			int currentval = *(dest + i);
			for (int k = 0; k < amtMain; k++) {
				if (currentval == *(dataC + k)) {
					overlapCount++;
					break;
				}
			}
		}
	}
	return overlapCount;
}
