#include "bintree.h"
#include <functional>
#include <queue>



/// <summary>
/// Initializes a new instance of the <see cref="BinTree" /> class.
/// </summary>
BinTree::BinTree()
{
}

/// <summary>
/// Initializes a new instance of the <see cref="BinTree" /> class.
/// </summary>
/// <param name="other">The other.</param>
BinTree::BinTree(const BinTree &other)
{
	*this = other;
}

/// <summary>
/// Finalizes an instance of the <see cref="BinTree" /> class.
/// </summary>
BinTree::~BinTree()
{
	makeEmpty();
	delete(root);
}

/// <summary>
/// Determines whether this instance is empty.
/// </summary>
/// <returns>
///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
/// </returns>
bool BinTree::isEmpty() const
{
	return numElems == 0;
}
/// <summary>
/// Trees the deleter.
/// </summary>
/// <param name="del">The delete.</param>
void BinTree::treeDeleter(Node* del)
{
	if( del->left != nullptr ) treeDeleter(del->left);
	if( del->right != nullptr ) treeDeleter(del->right);
	delete del;
}

/// <summary>
/// Makes the empty.
/// </summary>
void BinTree::makeEmpty()
{
	treeDeleter(root);
	root = new Node();
	treeHeight = numElems = 0;
}

/// <summary>
/// Operator=s the specified BST.
/// </summary>
/// <param name="bst">The BST.</param>
/// <returns></returns>
BinTree & BinTree::operator=(const BinTree &bst)
{
	if( this == &bst || &*(this->root) == &*(bst.root) )return *this;

	// if the root node of the other tree is nullptr, then we need only 
	// instanciate our own empty tree to effectively copy the bst reference.
	if( bst.root == nullptr ) {
		this->root = nullptr;
		return;
	}
	treeHeight = numElems = 0;
	

	// another edge case check that will permit us to make assumptions about the 
	// state of the tree later in the constructor.
	if( bst.root == nullptr ) {
		root = nullptr;
		return;
	}

	// If we are able to get this far, then it's safe to say that
	// bst does have a value stored in root, and we should proceed
	// with creating nodes to match those in bst.
	root = new Node();
	root->data = bst.root->data;
	treeHeight = numElems = 1;
	// when the root is also a leaf, there's nothing left to copy; 
	// this is the last edge case
	if( bst.root->isLeaf() ) {
		return;
	}
	// from here on, we have to assume that root exists, and has child nodes.

	// the earMark variable will be used to track when qwayway.front() has reached
	// the next level of nodes in bst.
	Node* earMark = new Node();
	// earMark->leftPtr = bst.
	std::queue<Node*> qwayway;
	qwayway.push(bst.root);
	qwayway.push(earMark);

	while( !(qwayway.empty()) ) {
		if( qwayway.front() == earMark ) {
			++treeHeight;
			qwayway.pop();
			if( qwayway.empty() )break;
			qwayway.push(earMark);
		}
		else {
			if( qwayway.front()->left != nullptr )qwayway.push(qwayway.front()->left);
			if( qwayway.front()->right != nullptr )qwayway.push(qwayway.front()->right);
			
			insert(qwayway.front()->data);
			++numElems;
			qwayway.pop();
		}
	} // end while-loop

	delete(earMark);

	// TODO: insert return statement here
}

/// <summary>
/// Operator==s the specified RHS.
/// </summary>
/// <param name="rhs">The RHS.</param>
/// <returns></returns>
bool BinTree::operator==(const BinTree &rhs) const
{
	return false;
}

/// <summary>
/// Operator!=s the specified .
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>
bool BinTree::operator!=(const BinTree &) const
{
	return false;
}

/// <summary>
/// Inserts the specified .
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>
bool BinTree::insert(NodeData *)
{

	return false;
}

/// <summary>
/// Retrieves the specified .
/// </summary>
/// <param name="target">The target.</param>
/// <param name="foundTarget">The found target.</param>
/// <returns></returns>
bool BinTree::retrieve(const NodeData& target, NodeData* foundTarget) const
{
	Node* seekPtr = root;
	Node* tarPtr = new Node();
	*(tarPtr->data) = *(foundTarget);
	if( retrieve(seekPtr, foundTarget) ) {
		foundTarget = tarPtr->data;
	}
	return *foundTarget == target;
}

/// <summary>
/// Retrieves the specified seek PTR.
/// </summary>
/// <param name="seekPtr">The seek PTR.</param>
/// <param name="tar">The tar.</param>
/// <returns></returns>
bool BinTree::retrieve(Node* seekPtr, const NodeData* tar) const
{
	while( seekPtr != nullptr && *(seekPtr->data) != *tar ) {
		if     ( tar < seekPtr->data )seekPtr = seekPtr->left;
		else if( tar > seekPtr->data )seekPtr = seekPtr->right;
	}
	return seekPtr->data == tar;
}

/// <summary>
/// Inorders the helper.
/// </summary>
inline void BinTree::inorderHelper() const
{
}


/// <summary>
/// Gets the height.
/// </summary>
/// <param name="dat">The data value to search for and if found, report the
/// height of.</param>
/// <returns></returns>
int BinTree::getHeight(const NodeData* dat) const
{
	int depth = 0;
	bool foundTarget = 0;
	queue<Node*> nodeQueue;
	// the earMark variable will be used to track when qwayway.front() has reached
	// the next level of nodes in bst.
	Node* earMark = new Node();

	nodeQueue.push(root);
	nodeQueue.push(earMark);

	while( !(nodeQueue.empty()) && nodeQueue.front()->data != dat ) {
		if( nodeQueue.front() == earMark ) {
			if(foundTarget)++depth;
			nodeQueue.pop();
			if( nodeQueue.empty() )break;
			nodeQueue.push(earMark);
		} else {
			if( !foundTarget && nodeQueue.front()->data == dat )foundTarget = 1;
			if( nodeQueue.front()->left != nullptr )nodeQueue.push(nodeQueue.front()->left);
			if( nodeQueue.front()->right != nullptr )nodeQueue.push(nodeQueue.front()->right);

			nodeQueue.pop();
		}
	} // end while-loop

	if( !nodeQueue.empty() ) {
		delete(earMark);
		++depth;
		earMark->left = nodeQueue.front()->left;
		earMark->right = nodeQueue.front()->right;
		while( !nodeQueue.empty() )nodeQueue.pop();
	}
	int l = 0, r = 0;
	auto lambDiver = []() {

	}
	while( earMark->left != nullptr ) {
		++l;
		earMark->left = earMark->left->left
	}

	/*int tmpLeft = (subTree->left != nullptr) ? 1 + diveDeep_ref(subTree->left, diveDeep_ref) : 0;
	int tmpRight = (subTree->right != nullptr) ? 1 + diveDeep_ref(subTree->right, diveDeep_ref) : 0;
	return (tmpLeft > tmpRight) ? tmpLeft : tmpRight;*/

	delete(earMark);

	return depth;
}


/// <summary>
/// Gets the height.
/// </summary>
/// <param name="dat">The data value to search for and if found, report the
/// height of.</param>
/// <returns></returns>
int BinTree::getHeight(const NodeData& dat)const {
	NodeData* nPtr;
	*nPtr = dat;
	int ret = getHeight(nPtr);
	nPtr = nullptr;
	delete(nPtr);
	return ret;
}

/// <summary>
/// Gets the height.
/// </summary>
/// <param name="dat">The data value to search for and if found, report the
/// height of.</param>
/// <returns></returns>
int BinTree::getHeight(const Node* dat)const {
	return getHeight(dat->data);
}

/// <summary>
/// Gets the height.
/// </summary>
/// <param name="dat">The data value to search for and if found, report the
/// height of.</param>
/// <returns></returns>
int BinTree::getHeight(const Node& dat)const {
	return getHeight(dat.data);
}

