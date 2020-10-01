#include "tree.h"
#include <iostream>
#include <cassert>

using namespace std;

Tree::Tree() : m_root{nullptr}
{ }

Tree::~Tree()
{
	delete m_root;
}

Node* Tree::find(const int value)
{
	return find(m_root, value);
}

void Tree::insert(const int value)
{
	insert(m_root, value);
}

void Tree::remove(const int value)
{
	remove(m_root, value);
}

void Tree::debug() const
{
	cout << "digraph tree {" << endl;
	cout << "\tgraph [truecolor = true, bgcolor = \"transparent\" ];" << endl;
	debug(m_root);
	cout << "}" << endl;
}

void Tree::print() const
{

}

Node* Tree::find(Node* cur, const int value)
{
}

void Tree::right_rotate(Node*& gparent)
{
}

void Tree::left_rotate(Node*& gparent)
{
}

void Tree::left_right_rotate(Node*& gparent)
{
	assert(gparent->m_left != nullptr);
	assert(gparent->m_left->m_right != nullptr);

	Node* left = gparent->m_left;	
	Node* lr = left->m_right;

	Node* tmp = lr->m_right;
	left->m_right = lr->m_left;
	lr->m_left = left;

	lr->m_right = gparent;
	gparent->m_left = tmp;

	gparent->set_height(max(height(gparent->m_left), height(gparent->m_right))+1);
	left->set_height(max(height(left->m_left), height(left->m_right))+1);
	lr->set_height(max(height(lr->m_left), height(lr->m_right))+1);
	gparent = lr;
}

void Tree::right_left_rotate(Node*& gparent)
{
}

void Tree::insert(Node*& cur, const int value)
{

}

Node* Tree::min(Node* const cur) const
{
	if (cur == nullptr)
		return nullptr;
	else if (cur->m_left == nullptr)
		return cur;
	else
		return min(cur->m_left);	
}

void Tree::remove(Node*& cur, const int value)
{

}

void Tree::print(Node* cur) const
{

}

void Tree::debug(Node* cur) const
{
	if (!cur) return;
	cout << "\t" << "node" << cur->value() << " " << "[ label = \"" << cur->value()  << " [" << cur->height() << "]\", fillcolor = blue, color = black, style = filled, fontcolor = white, fontsize = 24 ];" << endl;
	if (cur->m_left) {
		debug(cur->m_left);
		cout << "\tnode" << cur->value() << " -> " << "node" << cur->m_left->value() << "[ K = 0.1 ];" << endl;
	}
	else {
		cout << "left_null" << cur->value() << " [label=\"\", shape = none ];" << endl;
		cout << "\tnode" << cur->value() << " -> " << "left_null" << cur->value() << "[arrowhead = tee];" << endl;
	}

	if (cur->m_right) {
		debug(cur->m_right);
		cout << "\tnode" << cur->value() << " -> " << "node" << cur->m_right->value() << "[ K = 0.1 ];" << endl;
	}
	else {
		cout << "right_null" << cur->value() << " [label=\"\", shape = none ];" << endl;
		cout << "\tnode" << cur->value() << " -> " << "right_null" << cur->value() << "[arrowhead = tee];" << endl;
	}
}
