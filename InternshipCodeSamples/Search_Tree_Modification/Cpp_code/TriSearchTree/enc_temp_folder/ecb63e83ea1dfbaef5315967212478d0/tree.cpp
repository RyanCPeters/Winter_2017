
// The following definitions of Tree and Node are provided.
#include "tree.h"

using namespace std;

Node * Tree::getRoot() { return root; }

/*
* Implement the methods below.
*/
Tree::Tree() {
	root = nullptr;
}



void Tree::insert(int val) {
	if (root == nullptr) {
		root = new Node(val);
	}
	else {
		Node *seekPtr = root;
		while (val != seekPtr->val) {
			if (val < seekPtr->val) {
				if (seekPtr->left == nullptr) {
					seekPtr->left = new Node(val);
					seekPtr = nullptr;
					delete[] seekPtr;
					return;
				}
				else {
					seekPtr = seekPtr->left;
				}
			}
			else {
				if (seekPtr->right == nullptr) {
					seekPtr->right = new Node(val);
					seekPtr = nullptr;
					delete[] seekPtr;
					return;				
				}
				else {
					seekPtr = seekPtr->right;
				}
			} // end of if(val < seekPtr->val)-else block
		} // end while loop
		if (val == seekPtr->val) {
			while(seekPtr->mid != nullptr)seekPtr = seekPtr->mid;
			seekPtr->mid = new Node(val);
			return;
		}
	}
}

void Tree::remove(int val) {
	if (root->val == val) {
		delete[] root;
		root = nullptr;
	}
	else {
		Node *seekPtr = root, *prevPtr;
		int direction = 0; // -1 for left, 0 for mid, 1 for right;
		while (val != seekPtr->val) {
			if (val < seekPtr->val) {
				if (seekPtr->left == nullptr) {
					return;
				}
				else {
					direction = -1;
					prevPtr = seekPtr;
					seekPtr = seekPtr->left;
				}
			}
			else {
				if (seekPtr->right == nullptr) {
					return;
				}
				else {
					direction = 1;
					prevPtr = seekPtr;
					seekPtr = seekPtr->right;
				}
			} // end of if(val < seekPtr->val)-else block
		} // end while loop
		if (val == seekPtr->val) {
			if(seekPtr->mid != nullptr){
				direction = 0;
				while (seekPtr->mid != nullptr){
					prevPtr = seekPtr;
					seekPtr = seekPtr->mid;	
				}
				prevPtr->mid = nullptr;
				delete[](seekPtr);
				seekPtr = prevPtr = nullptr;
				delete[] seekPtr;
				delete[] prevPtr;
				return;
			}
			else if (seekPtr->left == nullptr && seekPtr->right == nullptr) {
				prevPtr = nullptr;
				delete[](prevPtr);
				delete[] seekPtr;
				return;
			}
			else  {
				Node *seekPtr2, *prevPtr2;
				if (seekPtr->left != nullptr) { 
					seekPtr2 = seekPtr->left->right, prevPtr2 = seekPtr->left;
					// we need to find the node containing the natural predecessor value to to the current node's value
					if (seekPtr->left->right != nullptr) {
						while (seekPtr2->right != nullptr) {
							prevPtr2 = seekPtr2;
							seekPtr2 = seekPtr2->right;
						}
						prevPtr2->right = seekPtr2->left;
					}
				}
				else if (seekPtr->right != nullptr) {
					if (seekPtr->right->left != nullptr) {
						seekPtr2 = seekPtr->right->left, prevPtr2 = seekPtr->right;
					
						while (seekPtr2->left != nullptr) {
							prevPtr2 = seekPtr2;
							seekPtr2 = seekPtr2->left;
						}
						prevPtr2->left = seekPtr2->right;
					}
				}
				seekPtr2->left = seekPtr->left;
				seekPtr2->right = seekPtr->right;
				prevPtr = seekPtr;
				seekPtr2 = prevPtr2 = prevPtr = seekPtr->left = seekPtr->right = nullptr;
				
				delete[] prevPtr;
				delete[] prevPtr2;
				delete[] seekPtr;
				delete[] seekPtr2;

			}
			return;
		}
	
	}
}
