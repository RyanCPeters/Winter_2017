
// default constructor, children set to nullptr as default
// item contained is undefined
template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode() {
	//ctor
}

// destructor
template<class ItemType>
inline BinaryNode<ItemType>::~BinaryNode() {
	// If suffering from memory leaks, uncomment next line
	// std::cout << "Deleting " << *this << std::endl;
	rightPtr = leftPtr = nullptr;
	delete(leftPtr);
	delete(rightPtr);
	delete this;
}

// constructor setting item
// left and right childPtr set to nullptr as default
template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode(const ItemType& item) : item{ item } {}

// true if no children, both leftPtr and rightPtr are nullptrs
template<class ItemType>
inline bool BinaryNode<ItemType>::isLeaf() const {
	return leftPtr == nullptr && rightPtr == nullptr;
}

// getter for left child
template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
	return leftPtr;
}

// setter for left child
template<class ItemType>
inline void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode* childPtr) {
	leftPtr = childPtr;
}

// getter for right child
template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
	return rightPtr;
}

// setter for left child
template<class ItemType>
inline void BinaryNode<ItemType>::setRightChildPtr(BinaryNode* childPtr) {
	rightPtr = childPtr;
}

// getter for item stored at node
template<class ItemType>
inline ItemType BinaryNode<ItemType>::getItem() const {
	return item;
}

// setter for item stored at node
template<class ItemType>
inline void BinaryNode<ItemType>::setItem(const ItemType& item) {
	this->item = item;
}