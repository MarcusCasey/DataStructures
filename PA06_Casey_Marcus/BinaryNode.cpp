// Marcus Casey
// CS 302
// Project 6

// import
#include <iostream>

using namespace std;

// inline header
template<class itemType>
class BinaryNode {
	public:
		BinaryNode ();
		BinaryNode (itemType createdVal, bool isRoot);
		~BinaryNode ();
		bool isLeftCleared ();
		bool isRootANode ();
		bool isChildren ();
		bool isRightCleared ();	
		void assignVal (itemType createdVal);
		void assignLeft (BinaryNode* newChild);
		void assignRight (BinaryNode* newChild);
		itemType getVal ();
		BinaryNode* returnRight ();
		BinaryNode* returnLeft ();
	private:
		BinaryNode* leftChild;
		BinaryNode* rightChild;
		itemType val;
		bool isRoot;
};
// constructor
template<class itemType>
BinaryNode<itemType>::BinaryNode () {
	leftChild = NULL;
	rightChild = NULL;
	isRoot = false;
}
// copy constructor
template<class itemType>
BinaryNode<itemType>::BinaryNode (itemType createdVal, bool isRoot) {
	leftChild = NULL;
	rightChild = NULL;
	val = createdVal;
	isRoot = isRoot;
}
// destructor
template<class itemType>
BinaryNode<itemType>::~BinaryNode () {
}
// assign left child
template<class itemType>
void BinaryNode<itemType>::assignLeft (BinaryNode* newChild) {
	leftChild = newChild;
	return;
}
// assign right child
template<class itemType>
void BinaryNode<itemType>::assignRight (BinaryNode* newChild) {
	rightChild = newChild;
	return;
}
// is right empty?
template<class itemType>
bool BinaryNode<itemType>::isRightCleared () {
	if (rightChild == NULL) {
		return true;
	} else {
		return false;
	}
}
// is the root a node?
template<class itemType>
bool BinaryNode<itemType>::isRootANode () {
	return isRoot;
}
// is left empty?
template<class itemType>
bool BinaryNode<itemType>::isLeftCleared () {
	if (leftChild == NULL){
		return true;

	} else {
		return false;
	}
}
// assign val
template<class itemType>
void BinaryNode<itemType>::assignVal (itemType createdVal){
	val = createdVal;
	return;
}
// return left 
template<class itemType>
BinaryNode<itemType>* BinaryNode<itemType>::returnLeft () {
	return leftChild;
}
// return right
template<class itemType>
BinaryNode<itemType>* BinaryNode<itemType>::returnRight () {
	return rightChild;
}
// get val
template<class itemType>
itemType BinaryNode<itemType>::getVal () {
	return val;
}
// is it a child?
template<class itemType>
bool BinaryNode<itemType>::isChildren () {
	if (leftChild != NULL || rightChild != NULL) {
		return true;
	} else {
		return false;
	}
}
