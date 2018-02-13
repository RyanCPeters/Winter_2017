#include "binarysearchtree.h"

using namespace std;

// stub file
// provided so that the BinarySearchTree can be compiled
// none of the functions are implemented


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
	:rootPtr(new BinaryNode<ItemType>()), treeHeight(0), numElems(0)
{
	// ctor
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	// dtor
	this->clear();
	delete(rootPtr);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
	:rootPtr(new BinaryNode<ItemType>(rootItem)), treeHeight(1), numElems(1)
{
}

// BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) 
// The copy constructor creates a 1-for-1 copy of the reference pointer bst.
// 
// If bst is an empty tree, then we create a basic empty tree in this constructor as well.
// 
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst)
{
	// if the root node of the other tree is nullptr, then we need only instanciate our own
	// empty tree to effectively copy the bst reference.
	if( bst.rootPtr == nullptr ) {
		this->rootPtr = nullptr;
		return;
	}
	treeHeight = numElems = 0;
	rootPtr = new BinaryNode<ItemType>();

	// another edge case check that will permit us to make assumptions about the 
	// state of the tree later in the constructor.
	if( bst.rootPtr == nullptr ) {
		rootPtr = nullptr;
		return;
	}

	// when the root is also a leaf, there's nothing left to copy; 
	// this is the last edge case
	if( bst.rootPtr->isLeaf() ) {
		rootPtr->setItem(bst.rootPtr->getItem());
		treeHeight = numElems = 1;
		return;
	}
	// from here on, we have to assume that root exists, and has child nodes.

	// the earMark variable will be used to track when qwayway.front() has reached
	// the next level of nodes in bst.
	BinaryNode<ItemType> * earMark = new BinaryNode<ItemType>();
	// earMark->leftPtr = bst.
	std::queue<BinaryNode<ItemType>*> qwayway;
	qwayway.push(bst.rootPtr);
	qwayway.push(earMark);

	while( !(qwayway.empty()) ) {
		if( qwayway.front() == earMark ) {
			++treeHeight;
			qwayway.pop();
			if( qwayway.empty() )break;
			qwayway.push(earMark);
		}
		else {
			if( !(qwayway.front()->isLeaf()) ) {
				if( qwayway.front()->getLeftChildPtr() != nullptr )qwayway.push(qwayway.front()->getLeftChildPtr());
				if( qwayway.front()->getRightChildPtr() != nullptr )qwayway.push(qwayway.front()->getRightChildPtr());
			}
			add(qwayway.front()->getItem());
			++numElems;
			qwayway.pop();
		}
	} // end while-loop

	delete(earMark);
} // end copy constructor

//
// 
template<class ItemType>
BinarySearchTree<ItemType> BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& otherBST)
{

	return BinarySearchTree<ItemType>();
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{ return numElems == 0; }

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return treeHeight;
}


template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return numElems;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item)
{
	if( numElems == 0 ) {
		treeHeight = numElems = 1;
		rootPtr->setItem(item);
	}
	else {
		int height = 1; // inits to 1 as that's the starting height at the root.

		BinaryNode<ItemType>* seekPtr = rootPtr;
		// setting up a lambda function to handle 
		// pointer navigation and height incrementing.
		// uses reference capturing notation [&] to use the
		// already instantiated variables height, and seekPtr.
		auto func = [&]() {
			++height;
			if( item > seekPtr->getItem() ) {
				if( seekPtr->getRightChildPtr() != nullptr ) {
					seekPtr = seekPtr->getRightChildPtr();
					return true;
				}
				else {
					seekPtr->setRightChildPtr(new BinaryNode<ItemType>(item));
					return false;
				}
			}
			else if( item < seekPtr->getItem() ) {
				if( seekPtr->getLeftChildPtr() != nullptr ) {
					seekPtr = seekPtr->getLeftChildPtr();
					return true;
				}
				else {
					seekPtr->setLeftChildPtr(new BinaryNode<ItemType>(item));
					return false;
				}
			}
			else return false;
		};

		while( func() );

		if( seekPtr->getItem() == item ) {
			seekPtr = nullptr;
			delete[] seekPtr;
			return false;
		}
		++numElems;
		treeHeight = (height > treeHeight) ? height : treeHeight;
		seekPtr = nullptr;
		delete[] seekPtr;

	}
	return true;
}

template<class ItemType>
void chainDeletion(BinaryNode<ItemType>* del)
{
	if( del->getLeftChildPtr() != nullptr ) chainDeletion(del->getLeftChildPtr());
	if( del->getRightChildPtr() != nullptr ) chainDeletion(del->getRightChildPtr());
	delete del;
}

// void BinarySearchTree<ItemType>::clear()
// calls the private function chainDeletion, which recursively seeks out leaves in the tree and
// starts to delete the tree on back towards the root.
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	chainDeletion(rootPtr);
	rootPtr = new BinaryNode<ItemType>();
	treeHeight = numElems = 0;
}



template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const
{
	BinaryNode<ItemType>* seekPtr = rootPtr;
	ItemType itm;
	bool ret = true;
	while( ret && seekPtr->getItem() != item ) {
		if( seekPtr->getItem() < item )   seekPtr = seekPtr->getRightChildPtr();
		else if( seekPtr->getItem() > item )seekPtr = seekPtr->getLeftChildPtr();
		ret = (seekPtr != nullptr);
	} // end while-loop
	if( !ret ) {
		delete[] seekPtr;
		return false;
	}
	itm = seekPtr->getItem();
	seekPtr = nullptr;
	delete(seekPtr);
	return itm == item;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr,
															BinaryNode<ItemType>* newNodePtr)
{
	subTreePtr = findNode(subTreePtr, newNodePtr->getItem());

	if( subTreePtr->getItem() == newNodePtr->getItem() )return subTreePtr;
	if( subTreePtr->getItem() > newNodePtr->getItem() ) return subTreePtr->setRightChildPtr(newNodePtr);
	if( subTreePtr->getItem() < newNodePtr->getItem() ) return subTreePtr->setLeftChildPtr(newNodePtr);
	return nullptr;
}  // end placeNode

// BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, 
//                                                            const ItemType& target) const
// return nullptr if can't find a node containing the given value.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
														   const ItemType& target) const
{
	if( target == subTreePtr->getItem() )return subTreePtr;
	else if( target > subTreePtr->getItem() ) {
		if( subTreePtr->getRightChildPtr() != nullptr ) return findNode(subTreePtr->getRightChildPtr());
		else return subTreePtr;
	}
	else {
		if( subTreePtr->getLeftChildPtr() != nullptr ) return findNode(subTreePtr->getLeftChildPtr());
		else return subTreePtr;
	}
}  // end findNode

// void BinarySearchTree<ItemType>::inorderTraverse(void visit(const ItemType&)) const
//
//	This function simply traverses the BinarySearchTree belonging to `this` and 
//	passes the nodes into the parameter visit (a function reference) which will then
//	perform some black box action on the value passed into it.
//
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(const ItemType& itm)) const
{
	stack<BinaryNode<ItemType>*> trackingStk;
	auto growLeft = [&trackingStk]() {
		while( trackingStk.top()->getLeftChildPtr() != nullptr )trackingStk.push(trackingStk.top()->getLeftChildPtr());
	};
	trackingStk.push(rootPtr);
	while( !(trackingStk.empty()) ) {
		growLeft();
		while( !(trackingStk.empty()) && trackingStk.top()->getRightChildPtr() == nullptr ) {
			visit(static_cast<ItemType>(trackingStk.top()->getItem()));
			trackingStk.pop();
		}
		if( !(trackingStk.empty()) && trackingStk.top()->getRightChildPtr() != nullptr ) {
			BinaryNode<ItemType>* tmp = trackingStk.top();
			trackingStk.pop();
			trackingStk.push(tmp->getRightChildPtr());
			visit(static_cast<ItemType>(tmp->getItem()));
			tmp = nullptr;
			delete(tmp);
		}
	}
}  // end inorder

   //
   // This overload of the inorderTraverse function provides a means to pass a lambda function as
   // the parameter, instead of a function reference.
   //
   //
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(std::function<void(const ItemType& itm)> func) const
{
	stack<BinaryNode<ItemType>*> stk;
	auto growLeft = [&stk]() {
		while( stk.top()->getLeftChildPtr() != nullptr )stk.push(stk.top()->getLeftChildPtr());
	};
	stk.push(rootPtr);
	while( !(stk.empty()) ) {
		growLeft();
		while( !(stk.empty()) && stk.top()->getRightChildPtr() == nullptr ) {
			func(static_cast<ItemType>(stk.top()->getItem()));
			stk.pop();
		}
		if( !(stk.empty()) && stk.top()->getRightChildPtr() != nullptr ) {
			BinaryNode<ItemType>* tmp = stk.top();
			stk.pop();
			stk.push(tmp->getRightChildPtr());
			func(static_cast<ItemType>(tmp->getItem()));
			tmp = nullptr;
			delete(tmp);
		}
	}
}  // end inorder

//
//  
//
// 
template<class ItemType>
void BinarySearchTree<ItemType>::rebalance()
{
	if( numElems < 1 )return;
	ItemType* arr = new ItemType[numElems];
	int pos = 0, hiBound = numElems; // we need hiBound to retain the node count after we clear the tree.
	auto func = [&](const ItemType& itm) {arr[pos++] = itm; };
	this->inorderTraverse(func);
	this->clear();
	this->buildBalancedTree(0, (hiBound - 1) / 2, hiBound - 1, arr);
	delete[] arr;
}

//
//  
//
// 
template<class ItemType>
void BinarySearchTree<ItemType>::buildBalancedTree(const int &l, const int& mid, const int &r, const ItemType arr[])
{
	this->add(arr[mid]);
	if( l <= mid - 1 )buildBalancedTree(l, (l + mid - 1) / 2, mid - 1, arr);
	if( r >= mid + 1 )buildBalancedTree(mid + 1, (r + mid + 1) / 2, r, arr);
}

// bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n)
// 
// 
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], const int& n)
{
	buildBalancedTree(0, (n - 1) / 2, n - 1, arr);
	return true;
}

//
//  
//
// 
template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const
{ sideways(rootPtr, 0); }

//
//  
//
// 
template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const
{
	if( current != nullptr ) {
		++level;

		if( current->getRightChildPtr() != nullptr ) {
			sideways(current->getRightChildPtr(), level);
		}

		// indent for readability, 4 spaces per depth level
		for( int i = level; i >= 0; --i ) {
			cout << "    ";
		}

		cout << current->getItem() << endl;        // display information of object
		if( current->getLeftChildPtr() != nullptr ) {
			sideways(current->getLeftChildPtr(), level);
		}


	}
}

//
//  
//
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const
{
	if( this == &other || this->rootPtr == other.rootPtr )return true;
	return matchyFunk((this->rootPtr), (other.rootPtr));
}

//
//  
//
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>* other) const
{
	if( this == other || this->rootPtr == other->rootPtr )return true;// first, the easy check against memory addresses
	return matchyFunk((this->rootPtr), (other->rootPtr)); // if we get here, we gotta compare node by node
}

// bool BinarySearchTree<ItemType>::matchyFunk(BinaryNode<ItemType>* local, BinaryNode<ItemType>* remote)
// 
// Helper function the performs tail-recursion in search for dissimilarities between this and the
// other parameter that was passed into the operator== overload.
template<class ItemType>
bool BinarySearchTree<ItemType>::matchyFunk(BinaryNode<ItemType>* local,
											BinaryNode<ItemType>* remote) const
{
	// the only way for either of the pointers to == nullptr and result in an equal state is if
	// both pointers are == nullptr; any other way and it's a false;
	if( (local == nullptr) ^ (remote == nullptr) ) {
		// We're here because:
		// 
		//   ( NOT ( local == nullptr XOR remote == nullptr )) came out to 0
		//   
		// Meaning only one of the parameter pointers passed into the 
		// function was equal to nullptr, and was thus, different from it's counterpart
		return false;

	}
	// if we passed the XOR check, then both local and remote are either pointing
	// towards instantiated nodes, or both towards nullptr. 
	// So, we check if we have a nullptr on one, knowing the other will match,
	// thus telling us to return up and out of this path.
	if( local == nullptr )return true;
	return local->getItem() == remote->getItem() &&
		matchyFunk(local->getLeftChildPtr(), remote->getLeftChildPtr()) &&
		matchyFunk(local->getRightChildPtr(), remote->getRightChildPtr());
}

//
//  
//
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const
{ return !(*this == other); }

//
//  
//
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>* other) const
{ return !(*this == *other); }
