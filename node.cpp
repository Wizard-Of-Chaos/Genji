#include "node.h"

Node::Node() : m_value{0}, m_height{1}, m_left{nullptr}, m_right{nullptr}, m_point{0,0}
{ }

Node::Node(const unsigned int value) : m_value{value}, m_height{1}, m_left{nullptr}, m_right{nullptr}
{ }

Node::~Node()
{
	if (m_left) delete m_left;
	if (m_right) delete m_right;
}

unsigned int Node::value() const
{
	return m_value;
}

int Node::height() const
{
	return m_height;
}

void Node::set_value(const unsigned int value)
{
	m_value = value;
}

void Node::set_height(const int height)
{
	m_height = height;
}

void Node::set_point(QPoint point)
{
	m_point = point;
}
