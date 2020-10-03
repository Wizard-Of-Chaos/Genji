#ifndef NODE_H
#define NODE_H
#include <QPoint>
#include <QList>
#include <QColor>

class Node {
	private:
	unsigned int m_key;
	QList<QPoint> m_point_list;
	int m_height;

	public:
	Node();
	Node(const unsigned int key);
	~Node();

	Node* m_left;
	Node* m_right;
	
	unsigned int key() const;
	int height() const;

	void set_key(const unsigned int key);
	void set_height(const int height);
	QList<QPoint>& list();
};
#endif //NODE_H
