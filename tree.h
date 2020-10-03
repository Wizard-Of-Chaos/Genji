#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <string>
#include <fstream>

using namespace std;

class Tree {
	private:
	Node* m_root;

	Node* find(Node* cur, const unsigned int key);
	void insert(Node*& cur, const unsigned int key);
	void remove(Node*& cur, const unsigned int key);
	void print(Node* cur, int counter) const;
	void debug(Node* cur) const;

	void left_rotate(Node*& gparent);
	void right_rotate(Node*& gparent);
	void left_right_rotate(Node*& gparent);
	void right_left_rotate(Node*& gparent);

	Node* min(Node* const cur) const;

	static int max(const int a, const int b)
	{
		return a >= b ? a : b;
	}

	static int height(Node* n) 
	{
		if (n == nullptr)
			return 0;
		return n->height();
	}

	public:
	Tree();
	~Tree();

	Node* find(const unsigned int key);
	void insert(const unsigned int key);
	void remove(const unsigned int key);
	void print() const;
	void debug() const;
};

#endif //TREE_H
