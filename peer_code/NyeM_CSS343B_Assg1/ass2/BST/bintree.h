#pragma once

#include "nodedata.h"
#include "bintree.h"

class BinTree {				// you add class/method comments and assumptions
	struct Node;
public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree &);
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;
	bool insert(NodeData*);
	bool retrieve(const NodeData& target, NodeData* foundTarget) const;
	void displaySideways() const;			// provided below, displays the tree sideways
	int getHeight(const NodeData* dat)const;
	int getHeight(const NodeData& dat)const;
	int getHeight(const Node* dat)const;
	int getHeight(const Node& dat)const;
	
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer

		Node() = default;
		bool isLeaf() {
			return left == nullptr && right == nullptr;
		};

		Node& operator=(const Node* rhs) {
			*this = *rhs;
			return *this;
		};

		Node& operator=(const Node& rhs) {
			if( this != &rhs ) {
				data = rhs.data;
			}
			return *this;
		};

		bool operator==(const Node& rhs) {
			return *data == *(rhs.data);
		};
	};
	Node* root;								// root of the tree

											// utility functions
	void inorderHelper(/*...*/) const;
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	void treeDeleter(Node* del);
	int treeHeight, numElems;

	bool retrieve( Node* seekPtr, const NodeData* tar) const;
	
};

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}



//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if( current != nullptr ) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for( int i = level; i >= 0; i-- ) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}