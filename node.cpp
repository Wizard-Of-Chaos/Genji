#include "node.h"

Node::Node() : m_key{0}, m_height{1}, m_left{nullptr}, m_right{nullptr}
{ }

Node::Node(const unsigned int value) : m_key{value}, m_height{1}, m_left{nullptr}, m_right{nullptr}
{ }

Node::~Node()
{
	if (m_left) delete m_left;
	if (m_right) delete m_right;
}

unsigned int Node::key() const
{
	return m_key;
}

int Node::height() const
{
	return m_height;
}

void Node::set_key(const unsigned int value)
{
	m_key = value;
}

void Node::set_height(const int height)
{
	m_height = height;
}

QList<QPoint>& Node::list()
{
	return m_point_list;
}
