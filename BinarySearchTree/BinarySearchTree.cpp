// Marcus Casey
// CS 302
// Project 6

// Imports
#include "BinaryNode.cpp"
#include <iostream>

using namespace std;

// inline class
template<class typeTemplate>
class BinarySearchTree {
	public:
		BinarySearchTree ();
		~BinarySearchTree ();
		void executeTraversals (int type);
		void clearTree ();
		void outputInfo ();
		bool isEmpty ();
		bool Sum(typeTemplate firstLoc);
		bool deleteThis (typeTemplate target);
		int getSize ();
		int getNodeAmount ();
	private:
		int nodeAmt;
		BinaryNode<typeTemplate>* topRoot;
// recursive FNC headers
		
		BinaryNode<typeTemplate>* deleteVal (BinaryNode<typeTemplate>* altTreeLoc, typeTemplate target, bool &isSuccessful);
		BinaryNode<typeTemplate>* deleteNode (BinaryNode<typeTemplate>* nodePtr);
		BinaryNode<typeTemplate>* deleteFarLeftNode (BinaryNode<typeTemplate>* nodePtr, typeTemplate &followerVal);
		BinaryNode<typeTemplate>* assignNode (BinaryNode<typeTemplate>* altTreeLoc, BinaryNode<typeTemplate>* newValNode);
// traverse fnc's
		void executePostOrderTraverse(BinaryNode<typeTemplate>* altTreeLoc);
		int amtChildren(BinaryNode<typeTemplate>* altTreeLoc);
		int amtHeight(BinaryNode<typeTemplate>* altTreeLoc);
		void executePreorderTraverse(BinaryNode<typeTemplate>* altTreeLoc);
		void executeInOrderTraverse(BinaryNode<typeTemplate>* altTreeLoc);
};
// constructor
template<class typeTemplate>
BinarySearchTree<typeTemplate>::BinarySearchTree() {
	topRoot = NULL;
	nodeAmt = 0;
}

// destructor
template<class typeTemplate>
BinarySearchTree<typeTemplate>::~BinarySearchTree() {
	delete topRoot;
	topRoot = NULL;

}
// is empty
template<class typeTemplate>
bool BinarySearchTree<typeTemplate>::isEmpty() {
	if (topRoot == NULL) {
		return true;

	} else {
		return false;
	}
}
// sum (add)
template<class typeTemplate>
bool BinarySearchTree<typeTemplate>::Sum(typeTemplate firstLoc) {
	if (isEmpty()) {
		topRoot = new BinaryNode<typeTemplate>(firstLoc, true);
		return true;
	} else {
		BinaryNode<typeTemplate>* newLeaf = new BinaryNode<typeTemplate>(firstLoc, false);
		assignNode(topRoot, newLeaf);
	}
}
// run traversal
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::executeTraversals(int type) {
	// preorder
	if (type == 0) {
		executePreorderTraverse(topRoot);
	// in order
	} else if (type == 1) {
		executeInOrderTraverse(topRoot);
	// post order
	} else if (type == 2) {
		executePostOrderTraverse(topRoot);
	} else {
		cout << "Invalid traversal type requested. Traversal failed." << endl;
	}
	return;
}
// delete specified
template<class typeTemplate>
bool BinarySearchTree<typeTemplate>::deleteThis(typeTemplate target) {
	bool isSuccessful = false;
	topRoot = deleteVal(topRoot, target, isSuccessful);
	return isSuccessful;
}
// getSize
template<class typeTemplate>
int BinarySearchTree<typeTemplate>::getSize() {
	return 1 + amtHeight(topRoot);
}
// nodeAmt (#)
template<class typeTemplate>
int BinarySearchTree<typeTemplate>::getNodeAmount() {
	return amtChildren(topRoot);

}
// clear Tree
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::clearTree() {
	delete topRoot;
	topRoot = NULL;
	nodeAmt = 0;
	return;
}
// outputInfo
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::outputInfo() {
	DebugPrint(topRoot);
	cout << "outputInfo job ended." << endl;
	return;
}
// in order traversal
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::executeInOrderTraverse(BinaryNode<typeTemplate>* altTreeLoc) {
	if(altTreeLoc == NULL) {
	} else {
		executeInOrderTraverse((*altTreeLoc).returnLeft());
		cout << (*altTreeLoc).getVal() << ", ";
		executeInOrderTraverse((*altTreeLoc).returnRight());
	}
	return;
}
// post order traversal
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::executePostOrderTraverse(BinaryNode<typeTemplate>* altTreeLoc) {
	if(altTreeLoc == NULL) {
	} else {
		executePostOrderTraverse((*altTreeLoc).returnLeft());
		executePostOrderTraverse((*altTreeLoc).returnRight());
		cout << (*altTreeLoc).getVal() << ", ";
	}
	return;
}
// assignNode
template<class typeTemplate>
BinaryNode<typeTemplate>* BinarySearchTree<typeTemplate>::assignNode(BinaryNode<typeTemplate>* altTreeLoc, BinaryNode<typeTemplate>* newValNode) {
	if (altTreeLoc == NULL) {
		return newValNode;
	} else if ((*altTreeLoc).getVal() > (*newValNode).getVal()) {
		BinaryNode<typeTemplate>* tempPtr = assignNode((*altTreeLoc).returnLeft(), newValNode);
		(*altTreeLoc).assignLeft(tempPtr);

	} else if ((*altTreeLoc).getVal() < (*newValNode).getVal()) {
		BinaryNode<typeTemplate>* tempPtr = assignNode((*altTreeLoc).returnRight(), newValNode);
		(*altTreeLoc).assignRight(tempPtr);
	}
	return altTreeLoc;
}
// delete val
template<class typeTemplate>
BinaryNode<typeTemplate>* BinarySearchTree<typeTemplate>::deleteVal(BinaryNode<typeTemplate>* altTreeLoc, typeTemplate target, bool &isSuccessful) {
	if (altTreeLoc == NULL) {
		isSuccessful = false;
	} else if ((*altTreeLoc).getVal() == target) {
		altTreeLoc = deleteNode(altTreeLoc);
		isSuccessful = true;
	} else if ((*altTreeLoc).getVal() > target) {
		BinaryNode<typeTemplate>* tempPtr = deleteVal((*altTreeLoc).returnLeft(), target, isSuccessful);
		(*altTreeLoc).assignLeft(tempPtr);
	} else {
		BinaryNode<typeTemplate>* tempPtr = deleteVal((*altTreeLoc).returnRight(), target, isSuccessful);
		(*altTreeLoc).assignRight(tempPtr);
	}
	return altTreeLoc;

}
// delete node
template<class typeTemplate>
BinaryNode<typeTemplate>* BinarySearchTree<typeTemplate>::deleteNode(BinaryNode<typeTemplate>* nodePtr) {
	if (!(*nodePtr).isRootANode() && !(*nodePtr).isChildren()) {
		delete nodePtr;
		nodePtr = NULL;

		return nodePtr;

	} else if((*nodePtr).returnLeft() != NULL && (*nodePtr).returnRight() == NULL) {
		BinaryNode<typeTemplate>* nodeToConnect = (*nodePtr).returnLeft();
		delete nodePtr;
		nodePtr = NULL;
		return nodeToConnect;
	} else if((*nodePtr).returnLeft() == NULL && (*nodePtr).returnRight() != NULL) {
		BinaryNode<typeTemplate>* nodeToConnect = (*nodePtr).returnRight();
		delete nodePtr;
		nodePtr = NULL;
		return nodeToConnect;
	} else {
		typeTemplate createdVal;
		BinaryNode<typeTemplate>* tempPtr = deleteFarLeftNode ((*nodePtr).returnRight(), createdVal);
		(*nodePtr).assignRight(tempPtr);
		(*nodePtr).assignVal(createdVal);
		return nodePtr;
	}
}
// delete far left node
template<class typeTemplate>
BinaryNode<typeTemplate>* BinarySearchTree<typeTemplate>::deleteFarLeftNode (BinaryNode<typeTemplate>* nodePtr, typeTemplate &followerVal) {
	if ((*nodePtr).returnLeft() == NULL) {
		followerVal = (*nodePtr).getVal();
		return deleteNode(nodePtr);
	} else {
		BinaryNode<typeTemplate>* tempPtr = deleteFarLeftNode((*nodePtr).returnLeft(), followerVal);
		(*nodePtr).assignLeft(tempPtr);
		return nodePtr;
	}
}
// how many children
template<class typeTemplate>
int BinarySearchTree<typeTemplate>::amtChildren(BinaryNode<typeTemplate>* altTreeLoc) {
	if ((*altTreeLoc).returnLeft() != NULL && (*altTreeLoc).returnRight() == NULL) {
		return 1 + amtChildren((*altTreeLoc).returnLeft());
	} else if ((*altTreeLoc).returnLeft() == NULL && (*altTreeLoc).returnRight() != NULL) {
		return 1 + amtChildren((*altTreeLoc).returnRight());		
	} else if ( !(*altTreeLoc).isChildren()) {
		return 1;
	} else {
		int count = 0;
		count += amtChildren((*altTreeLoc).returnLeft());
		count += amtChildren((*altTreeLoc).returnRight());
		return 1 + count; 
	}
}
// what size
template<class typeTemplate>
int BinarySearchTree<typeTemplate>::amtHeight(BinaryNode<typeTemplate>* altTreeLoc) {
	int leftHeight = 0;
	int rightHeight = 0;
	if ((*altTreeLoc).returnLeft() != NULL) {
		leftHeight = 1 + amtHeight((*altTreeLoc).returnLeft());
	}

	if ((*altTreeLoc).returnRight() != NULL) {
		rightHeight = 1 + amtHeight((*altTreeLoc).returnRight());
	}

	if (leftHeight >= rightHeight) {
		return leftHeight;
	} else {
		return rightHeight;
	}
}

// execute preorder traversal
template<class typeTemplate>
void BinarySearchTree<typeTemplate>::executePreorderTraverse(BinaryNode<typeTemplate>* altTreeLoc) {
	if(altTreeLoc == NULL) {
	} else {
		cout << (*altTreeLoc).getVal() << ", ";
		executePreorderTraverse((*altTreeLoc).returnLeft());
		executePreorderTraverse((*altTreeLoc).returnRight());
	}
	return;
}
