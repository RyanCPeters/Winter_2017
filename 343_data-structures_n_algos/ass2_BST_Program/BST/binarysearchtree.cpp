
using namespace std;

// stub file
// provided so that the BinarySearchTree can be compiled
// none of the functions are implemented


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
	:rootPtr(new BinaryNode<ItemType>()), treeHeight(0), numElems(0)
{
	//ctor
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	//dtor
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
	//earMark->leftPtr = bst.
	std::queue<BinaryNode<ItemType>*> qwayway;
	qwayway.push(bst.rootPtr);
	qwayway.push(earMark);

	while( !(qwayway.empty()) ) {
		if( qwayway.front() == earMark ) {
			++treeHeight;
			qwayway.pop();
			if( qwayway.empty() )break;
			qwayway.push(earMark);
		} else {
			if( !(qwayway.front()->isLeaf()) ) {
				if( qwayway.front()->getLeftChildPtr() != nullptr )qwayway.push(qwayway.front()->getLeftChildPtr());
				if( qwayway.front()->getRightChildPtr() != nullptr )qwayway.push(qwayway.front()->getRightChildPtr());
			}
			add(qwayway.front()->getItem());
			++numElems;
			qwayway.pop();
		}
	} // end while-loop

	delete[] earMark;
} // end copy constructor

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
	} else {
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
				} else {
					seekPtr->setRightChildPtr(new BinaryNode<ItemType>(item));
					return false;
				}
			} else if( item < seekPtr->getItem() ) {
				if( seekPtr->getLeftChildPtr() != nullptr ) {
					seekPtr = seekPtr->getLeftChildPtr();
					return true;
				} else {
					seekPtr->setLeftChildPtr(new BinaryNode<ItemType>(item));
					return false;
				}
			} else return false;
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

// BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const
// return nullptr if can't find a node containing the given value.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
														   const ItemType& target) const
{
	if( target == subTreePtr->getItem() )return subTreePtr;
	else if( target > subTreePtr->getItem() ) {
		if( subTreePtr->getRightChildPtr() != nullptr ) return findNode(subTreePtr->getRightChildPtr());
		else return subTreePtr;
	} else {
		if( subTreePtr->getLeftChildPtr() != nullptr ) return findNode(subTreePtr->getLeftChildPtr());
		else return subTreePtr;
	}
}  // end findNode

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(const ItemType&)) const
{
	stack<BinaryNode<ItemType>*> stk;
	auto growLeft = [&stk]() {
		while( stk.top()->getLeftChildPtr() != nullptr )stk.push(stk.top()->getLeftChildPtr());
	};
	stk.push(rootPtr);
	while( !(stk.empty()) ) {
		growLeft();
		while( !(stk.empty()) && stk.top()->getRightChildPtr() == nullptr ) {
			visit(static_cast<ItemType>(stk.top()->getItem()));
			stk.pop();
		}
		if( !(stk.empty()) && stk.top()->getRightChildPtr() != nullptr ) {
			BinaryNode<ItemType>* tmp = stk.top();
			stk.pop();
			stk.push(tmp->getRightChildPtr());
			visit(static_cast<ItemType>(tmp->getItem()));
			tmp = nullptr;
			delete(tmp);
		}
	}
}  // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::rebalance()
{ }

// bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n)
// 
// 
// 
template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n)
{ 
	// i will be used to check if the parameter 'arr' has been passed in
	// the correct ordering to satisfy an array based BST
	//
	// if 'arr' fails to prove itself ordered as a BST, i will exit the
	// test loop at a value greater than 0. This saves us from having to
	// create a bool variable to track things.
	int i = n - 1;

	// Appologies for the bit-shifting black-magic vudu in the following
	// for loop here...
	// 
	// A special note on the expression: 
	//                 i/2 - (((i << 31) >> 31) ^ 1)
	// where (i << 31) >> 31) is bit-shifting the 32-bit int, i, 
	// so as to purge all bit data except the 2^0 bit, thus giving us
	// the odd or even state for that bit with less overhead than if we
	// were to use i%2
	// 
	// The use of the XOR operator `^` is a low cost means to ensure that
	// we only subtract 1 from i if i is even. 
	// 
	// We do this because we want to check each index in arr, from n-1 to 1, 
	// against its parrent value (assuming arr is an array based binary tree)
	//
	// for example: 
	//              The left child node of index position 3 in an array is at
	//              index position: 3*2+1 = 7
	//              And the right child noe is at: 3*2+2 = 8
	//
	//              If we want to traverse the tree in reverse order, we need to
	//              first divide by 2, then if idx is even we need to subtract 1;
	//              the expression will look like this:
	//              left child seeking parent: 7/2 - 0 = 3;
	//              right child seeking parent: 8/2 - 1 = 3;
	// 
	// This works, in part, due to integer division trunkating any remainder to 0
	for( ; i > 0; --i ) {
		if( ((i << 31) >> 31) ^ 1 ) {
			// right child node should be greater than parent
			if( arr[(i / 2) - 1] > arr[i] )break;// if parent greater than right child, break out of for loop early
		} else {
			// left child node should be less than parent
			if( arr[i / 2] < arr[i] )break;// if parent is less than left child node, break out of for loop early
		}
	}

	// now, based upon state of 'i', we decide if arr needs to be re-ordered, or if we can go ahead and create 
	// the node based BST.
	if( i > 0 ) { // 'arr' isn't ordered as an array-based BST
		int idx = 0; // a pointer for tracking our position in arr as we update it in proper BST order
		auto filterDownLamb = [&](ItemType& itm) {arr[idx] = itm; ++idx; };
		auto perkolateUpLamb = [&](ItemType& itm) { };
	}
	else { // joy, all we have to do is start adding values to our tree from arr, in order from 0 to n-1
		this->clear();
		for( int k = 0; k < n; ++k )this->add(arr[k]);
	}

	

	
	return true; 
}


template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const
{ sideways(rootPtr, 0); }

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

template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const
{
	if( this == &other || this->rootPtr == other.rootPtr )return true;
	return matchyFunk((this->rootPtr), (other.rootPtr));
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

template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const
{ return !(*this == other); }