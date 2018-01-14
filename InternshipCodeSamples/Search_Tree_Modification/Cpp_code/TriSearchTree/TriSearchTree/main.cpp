#include "tree.cpp"
#include <iostream>


int main() {
	Tree modBST = Tree();
	// insert 7,10,10
	// delete 10
	modBST.insert(7);
	modBST.insert(10);
	modBST.insert(10);

	modBST.remove(10);
}