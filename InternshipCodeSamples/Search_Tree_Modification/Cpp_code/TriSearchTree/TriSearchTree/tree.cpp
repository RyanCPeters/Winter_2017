
// The following definitions of Tree and Node are provided.

using namespace std;

struct Node {
	int val;
	Node *left, *mid, *right;
	Node(int val) : left(0), mid(0), right(0), val(val) {}
};

class Tree {
	public:
	Tree();
	void insert(int val);
	void remove(int val);
	Node * getRoot();
	protected:
	Node *root;
};


Node * Tree::getRoot() { return root; }

/*
* Implement the methods below.
*/
Tree::Tree() {
	root = nullptr;
}

Node* findNode(Node* seekPtr, Node* prevPtr, const int &val) {
	while (seekPtr != nullptr && val != (seekPtr->val)) {
		while (seekPtr != nullptr && val < seekPtr->val) {
			prevPtr = seekPtr;
			seekPtr = seekPtr->left;
		}
		while (seekPtr != nullptr && val > seekPtr->val) {
			prevPtr = seekPtr;
			seekPtr = seekPtr->right;
		}
	}
	
	if(seekPtr != nullptr) {
		while (seekPtr->mid != nullptr) seekPtr = seekPtr->mid;
		prevPtr = seekPtr;
	}
	return prevPtr;
}

void Tree::insert(int val) {
	if (root == nullptr) {
		root = new Node(val);
	}
	else {
		Node *seekPtr = root;
		while (seekPtr != nullptr && val != seekPtr->val) {
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
			}
		}
		/*
		if (val == root->val) {
			if (root->mid == nullptr) {
				root->mid = new Node(val);
				prevPtr = seekPtr = nullptr;
				delete[] prevPtr;
				delete[] seekPtr;
				return;
			}
			seekPtr = root->mid;
			while(seekPtr->mid != nullptr) seekPtr = seekPtr->mid;
			seekPtr->mid = new Node(val);
			if (val == seekPtr->val) seekPtr->mid = new Node(val);
			else if(val < seekPtr->val)seekPtr->left = new Node(val);
			else if(val > seekPtr->val)seekPtr->right = new Node(val);
			prevPtr = seekPtr = nullptr;
			delete[] prevPtr;
			delete[] seekPtr;
			return;
		}
		else if (val < root->val) seekPtr = root->left;		
		else	seekPtr = root->right;
		seekPtr = findNode(seekPtr,prevPtr,val);

		if (seekPtr == nullptr) {
			if (val < prevPtr->val) prevPtr->left = new Node(val);
			else if (val > prevPtr->val) prevPtr->right = new Node(val);
		}
		*/
	}
}

void Tree::remove(int val) {
	
}
