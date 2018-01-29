#include "bintree.h"
#include <queue>



BinTree::BinTree()
{
}

BinTree::BinTree(const BinTree &)
{
}

BinTree::~BinTree()
{
	makeEmpty();
	delete(root);
}

bool BinTree::isEmpty() const
{
	return numElems == 0;
}
void BinTree::treeDeleter(Node* del)
{
	if( del->left != nullptr ) treeDeleter(del->left);
	if( del->right != nullptr ) treeDeleter(del->right);
	delete del;
}
void BinTree::makeEmpty()
{
	treeDeleter(root);
	root = new Node();
	treeHeight = numElems = 0;
}

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

bool BinTree::operator==(const BinTree &rhs) const
{
	return false;
}

bool BinTree::operator!=(const BinTree &) const
{
	return false;
}

bool BinTree::insert(NodeData *)
{

	return false;
}

bool BinTree::retrieve(...) const
{
	return false;
}


inline void BinTree::inorderHelper() const
{
}