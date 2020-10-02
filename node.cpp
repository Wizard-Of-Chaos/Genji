#include "node.h"

Node::Node() : m_value{0}, m_height{1}, m_left{nullptr}, m_right{nullptr}, m_point{0,0}
{ }

Node::Node(const int value) : m_value{value}, m_height{1}, m_left{nullptr}, m_right{nullptr}
{ }

Node::~Node()
{
	if (m_left) delete m_left;
	if (m_right) delete m_right;
}

int Node::value() const
{
	return m_value;
}

int Node::height() const
{
	return m_height;
}

void Node::set_value(const int value)
{
	m_value = value;
}

void Node::set_height(const int height)
{
	m_height = height;
}
