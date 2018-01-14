#pragma once

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
	Node * root;
};