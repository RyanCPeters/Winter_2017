#include "binarynode.h"
#include "binarysearchtree.h"

template<class ItemType>
inline BinarySearchTree<ItemType>::BinarySearchTree() {}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType & rootItem) {}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
	return false;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
	return 0;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
	return 0;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & item) {
	return false;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType & item) const {
	return false;
}

// based on code from Zander
// display ascii version of tree sideways
template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
	sideways(rootPtr, 0);
}

// display ascii version of tree sideways recursively
template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
	if (current != nullptr) {
		++level;
		sideways(current->getRightChildPtr(), level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; --i) {
			cout << "    ";
		}

		cout << current->getItem() << endl;        // display information of object
		sideways(current->getLeftChildPtr(), level);
	}
}