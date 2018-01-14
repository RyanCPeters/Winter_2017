#include "tree.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
	Tree modBST = Tree();
	// insert 7,10,10
	// delete 10
	vector<int> inserts = { 5,4,9,5,7,2,2,1,2,3,10,15,12,11 };
	vector<int> deletes = {2,1,9,10};
	int lastInsert = 4;

	
	for (const auto i : inserts) {
		modBST.insert(i);
	}
	for (const auto j : deletes) {
		modBST.remove(j);
	}
	modBST.insert(lastInsert);


}