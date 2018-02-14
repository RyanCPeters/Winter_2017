// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// some interactive and non-interactive testes to test BinarySearchTree

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <cctype>
#include "binarysearchtree.h"
#include "binarynode.h"

using namespace std;
//union StrInt {
//	int8_t smalInt;
//	int16_t medInt;
//	int32_t bigInt;
//	char c;
//	string s;
//
//};

//so if you ever need to try and meet up on campus you can
template<class ItemType>
void itemDisplay(const ItemType& anItem) {
	cout << anItem << " ";
}

string getString() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	return str;
}

int getInt() {
	int num;
	cout << "Enter an int: ";
	cin >> num;
	return num;
}

vector<int> getInts(const string& inFileName ) {
	/*cout << "Enter multiple ints: ";
	cin.clear();*/
	
	vector<int> v;
	int num;
	ifstream iFile(inFileName);
	if( iFile.is_open() ) {
		while( iFile >> num ) {
			v.push_back(num);
		}
	}
	return v;
}

void getStrings(vector<string>& v) {
	// A = 65, Z = 90, a = 97, z = 122;
	// char c; ((c >= 65 && c <= 90) || (c>=97 && c <= 122))
	
	cout << "Please enter the name of the input file to use.\n"
		"The name should have no spaces and the file type should be .txt \n"
		"\neg., \"many-int-test.txt\"\n>> ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	string fileName;
	getline(cin, fileName);
	ifstream iFile(fileName);
	if( iFile.is_open() ) {
		while( iFile ) {
			stringstream ss;
			while( std::isspace(iFile.peek())) 
				iFile.get();
			while( std::isalnum(iFile.peek())) 
				ss << static_cast<char>(iFile.get());
			if( std::isalnum(ss.peek()) ) v.push_back(ss.str());
			
		}
	}
}

void treeMenuString() {
	BinarySearchTree<string> bst;
	BinarySearchTree<string>* bstPtr;
	const string menu = "treeMenuString\n"
        "0. Display tree sideways\n"
		"1. Add\n2. Search\n"
		"3. Inorder traverse\n"
		"4. Height & Number of nodes\n"
		"5. Rebalance\n"
		"6. Add Multiple\n"
		"7. Clear tree\n"
		"8. Create tree from sorted array\n"
		"9. Create duplicate tree\n"
		"10. Exit\n>> ";
	
	
	cout << menu;
	while (true) {
		int choice;
		string str;
		vector<string> v;
		cin >> choice;
		switch (choice) {
            case 0:
                bst.displaySideways();
                break;
			case 1:
				str = getString();
				cout << (bst.add(str) ? "" : "Not ") << "Added " << str << endl;
				break;
			case 2:
				str = getString();
				cout << (bst.contains(str) ? "" : "Not ") << "Found " << str << endl;
				break;
			case 3:
				bst.inorderTraverse(itemDisplay);
				cout << endl;
				break;
			case 4:
				cout << "Height: " << bst.getHeight() << endl;
				cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
				break;
			case 5:
				bst.rebalance();
				break;
			case 6:
				
				getStrings(v);
				for (const string& ele :v ) cout << (bst.add(ele) ? "" : "Not ") << "Added " << ele << endl;
//				bst.displaySideways();
//				bst.rebalance();
				break;
			case 7:
				bst.clear();
				break;
			case 8:
				{
					bst.clear();
					getStrings(v);
					bst.readTree(&v[0], v.size());
					cout << "Height: " << bst.getHeight() << endl;
					cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
					break;
				}
			
			case 10:
				{
					bst.clear();
					return;
				}
			case 9:
				if( !bst.isEmpty() ) {
					bstPtr = new BinarySearchTree<string>(bst);
					cout << ((bst == *bstPtr) ? "OK" : "ERR") << ": bst == *bstPtr" << endl;
					cout << ((bst == bstPtr) ? "OK" : "ERR") << ": bst == bstPtr" << endl;
					cout << "printing bstPtr\n";
					bstPtr->inorderTraverse(itemDisplay);
					cout << endl;
					delete(bstPtr);
					cout << "deleted bstPtr" << endl;
//					cout << "delete(bstPtr);\n\tDid it work?\n" << "\tHeight: " << bstPtr->getHeight() << endl;
//					cout << "\tNumber of nodes: " << bstPtr->getNumberOfNodes() << endl;
					cout << "now to print bst to confirm it is unchanged" << endl;
					break;
				}
				cout << "\n\t\tOops! You will need to build an initial reference BST first!\n";
			default:
				cout << "Bad input" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
		}

		cout << menu;
	}
}


void treeMenuInt() {
	BinarySearchTree<int> bst;
	const string menu = "treeMenuInt\n"
		"1. Add\n"
		"2. Search\n"
		"3. Inorder traverse\n"
		"4. Height & Number of nodes\n"
		"5. Rebalance\n"
		"6. Add Multiple\n"
		"7. Clear tree\n"
		"10. Exit\n>> ";
	int choice;
	
	cout << menu;
	while (true) {
		int number;
		string fileName;
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter a number: ";
				cin >> number;
				cout << (bst.add(number) ? "" : "Not ") << "Added " << number << endl;
				break;
			case 2:
				number = getInt();
				cout << (bst.contains(number) ? "" : "Not ") << "Found " << number << endl;
				break;
			case 3:
				bst.inorderTraverse(itemDisplay);
				cout << endl;
				break;
			case 4:
				cout << "Height: " << bst.getHeight() << endl;
				cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
				break;
			case 5:
				bst.rebalance();
				break;
			case 6:
				cout << "Please enter the name of the input file to use.\n"
					"The name should have no spaces and the file type should be .txt \n"
					"\neg., \"many-int-test\"\n>> ";
				cin.clear();
				cin >> fileName;
				for( const int& val : getInts(fileName) ) {
					cout << (bst.add(val) ? "" : "Not ") << "Added " << val << endl;
				}
				break;
			case 10:
				bst.clear();
				return;
			default:
				cout << "Bad input" << endl;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
		}
		bst.displaySideways();
		cout << menu;
	}
}

int main() {
	BinarySearchTree<string> bst1;
	BinarySearchTree<string> bst2;
	bst1.add("g");
	bst1.add("d");
	bst1.add("k");
	cout << ((bst1 != bst2) ? "OK" : "ERR") << ": bst1 != bst2" << endl;
	bst2.add("g");
	bst2.add("d");
	bst2.add("k");
	cout << ((bst1 == bst2) ? "OK" : "ERR") << ": bst1 == bst2" << endl;
	cout << (bst1.contains("d") ? "OK" : "ERR") << ": bst1 contains d" << endl;
	cout << (bst1.contains("x") ? "ERR" : "OK") << ": bst1 does not contain x" << endl;
	cout << (bst1.add("g") ? "ERR" : "OK") << ": adding g second time returns false" << endl;
	treeMenuString();
	//treeMenuInt();
	cin.get();
	return 0;
}
