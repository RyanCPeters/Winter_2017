
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
	root = new Node();
}

void Tree::insert(int val) {
	if(root == nullptr)
}

void Tree::remove(int val) {

}
