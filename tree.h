#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <string>
#include <fstream>

using namespace std;

class Tree {
	private:
	Node* m_root;

	Node* find(Node* cur, const QRgb key);
	void insert(Node*& cur, const QRgb key);
	void remove(Node*& cur, const QRgb key);
	void print(Node* cur, int counter) const;
	void debug(Node* cur) const;

	void left_rotate(Node*& gparent);
	void right_rotate(Node*& gparent);
	void left_right_rotate(Node*& gparent);
	void right_left_rotate(Node*& gparent);

	void keys(Node* cur, vector<QRgb> & keys);

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

	Node* find(const QRgb key);
	void insert(const QRgb key);
	void remove(const QRgb key);
	void print() const;
	void debug() const;
	vector<QRgb> keys();
};

#endif //TREE_H
