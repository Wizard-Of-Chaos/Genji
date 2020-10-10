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

Node* Tree::find(const QRgb value)
{
	return find(m_root, value);
}

void Tree::insert(const QRgb value)
{
	insert(m_root, value);
}

void Tree::remove(const QRgb value)
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
	int counter = 0;
	print(m_root, counter);
}

Node* Tree::find(Node* cur, const QRgb value)
{
  if (cur == nullptr || cur->key() == value)
    	return cur;

  if (value < cur->key())
    	return find(cur->m_left, value);

  return find(cur->m_right, value);
}

void Tree::right_rotate(Node*& gparent)
{
  	Node* left = gparent->m_left;
	Node* tmp = left->m_right;
	left->m_right = gparent;
	gparent->m_left = tmp;

	int maxheight;

	maxheight = max(height(gparent->m_right), height(gparent->m_left));

	gparent->set_height(maxheight + 1);

	maxheight = max(height(left->m_right), height(left->m_left));

	left -> set_height(maxheight + 1);

	gparent = left;
}

void Tree::left_rotate(Node*& gparent)
{
  	Node* right = gparent->m_right;
  	Node* tmp = right->m_left;
	right->m_left = gparent;
	gparent->m_right = tmp;

	int maxheight;

	maxheight = max(height(gparent->m_left), height(gparent->m_right));
	
	gparent->set_height(maxheight + 1);

	maxheight = max(height(right->m_left), height(right->m_right));

	right -> set_height(maxheight + 1);

	gparent = right;
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
  	assert(gparent->m_right != nullptr);
	assert(gparent->m_right->m_left != nullptr);

	Node* right = gparent->m_right;
	Node* rl = right->m_left;

	Node* tmp = rl->m_left;
	right->m_left = rl->m_right;
	rl->m_right = right;

	rl->m_left = gparent;
	gparent->m_right = tmp;

	gparent->set_height(max(height(gparent->m_right), height(gparent->m_left))+1);
	right->set_height(max(height(right->m_right), height(right->m_left))+1);
	rl->set_height(max(height(rl->m_right), height(rl->m_left))+1);
	gparent = rl;
}

void Tree::insert(Node*& cur, const QRgb value)
{
	Node* val = find(value);
	if(val) {
		return;
	}
	Node* n = new Node(value);
	if(cur == nullptr) //If at leaf, insert node
	{
	  cur = n;

	  return;
	}
	else if(value <= cur->key())
	{
	  insert(cur->m_left, value);
	}
	else
	{
	  insert(cur->m_right,value);
	}

	int max_height = max(height(cur->m_left), height(cur->m_right));
	cur -> set_height(max_height + 1);

	//Rebalancing vvvv

	if(height(cur->m_left) - height(cur->m_right) > 1)
	    {
	      Node* left = cur->m_left;
	      Node* left_gchild = left->m_left;
	      Node* right_gchild = left->m_right;

		if(height(left_gchild) > height(right_gchild))
		{
		  right_rotate(cur);
		}	
		else
		{
		  left_right_rotate(cur);
		}
	    }
	 
	 else if(height(cur->m_right) - height(cur->m_left) > 1)
	 {
	   Node* right = cur->m_right;
	   Node* left_gchild = right->m_left;
	   Node* right_gchild = right->m_right;

	   if(height(left_gchild) > height(right_gchild))
	   {
	     right_left_rotate(cur);
	   }
   	   else
	   {
	     left_rotate(cur);
	   }	     
	 }
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

void Tree::remove(Node*& cur, const QRgb value)
{
	if(cur == nullptr) {
		return;
	}
	if (value < cur->key()) {
		remove(cur->m_left, value);
	} else if (value > cur->key()) {
		remove(cur->m_right, value);
	} else {
		if(cur->m_right == nullptr && cur->m_left == nullptr) {
			delete cur;
			cur = nullptr;
		} else if(cur->m_right == nullptr) {
			Node* tmp = cur;
			cur = cur->m_left;
			delete tmp;
		} else if(cur->m_left == nullptr) {
			Node* tmp = cur;
			cur = cur->m_right;
			delete tmp;
		} else {
			Node* tmp = min(cur->m_right);
			cur->list() = tmp->list();
			cur->set_key(value);
			remove(cur->m_right, tmp->key());
		}
	}
}

void Tree::print(Node* cur, int count) const
{
	if (!cur) return;
	++count;
	cout << "Current node has value " << cur->key() << " and height " << cur->height() << ". This is node #" << count << "." << endl;
	if (cur->m_left) {
		cout << "Found left node." << endl;
		print(cur->m_left, count);
	}
	if (cur->m_right) {
		cout << "Found right node." << endl;
		print(cur->m_right, count);
	}
}

vector<QRgb> Tree::keys()
{
	vector<QRgb> key_rgbs;
	keys(m_root, key_rgbs);
	return key_rgbs;
}

void Tree::keys(Node* cur, vector<QRgb> & key_rgbs)
{
	if(!cur) return;
		key_rgbs.push_back(cur->key());
		cout << cur->key() << endl;
		if (cur->m_left)
		  keys(cur->m_left, key_rgbs);
		if (cur->m_right)
		  keys(cur->m_right, key_rgbs);

}


void Tree::debug(Node* cur) const
{
	if (!cur) return;
	cout << "\t" << "node" << cur->key() << " " << "[ label = \"" << cur->key()  << " [" << cur->height() << "]\", fillcolor = blue, color = black, style = filled, fontcolor = white, fontsize = 24 ];" << endl;
	if (cur->m_left) {
		debug(cur->m_left);
		cout << "\tnode" << cur->key() << " -> " << "node" << cur->m_left->key() << "[ K = 0.1 ];" << endl;
	}
	else {
		cout << "left_null" << cur->key() << " [label=\"\", shape = none ];" << endl;
		cout << "\tnode" << cur->key() << " -> " << "left_null" << cur->key() << "[arrowhead = tee];" << endl;
	}

	if (cur->m_right) {
		debug(cur->m_right);
		cout << "\tnode" << cur->key() << " -> " << "node" << cur->m_right->key() << "[ K = 0.1 ];" << endl;
	}
	else {
		cout << "right_null" << cur->key() << " [label=\"\", shape = none ];" << endl;
		cout << "\tnode" << cur->key() << " -> " << "right_null" << cur->key() << "[arrowhead = tee];" << endl;
	}
}
