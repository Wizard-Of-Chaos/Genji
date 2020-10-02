#ifndef NODE_H
#define NODE_H
#include <QPoint>

class Node {
	private:
	int m_value;
	QPoint m_point;
	int m_height;

	public:
	Node();
	Node(const int value);
	~Node();

	Node* m_left;
	Node* m_right;
	
	int value() const;
	int height() const;

	void set_value(const int value);
	void set_height(const int height);
	void set_point(const QPoint point);

};
#endif //NODE_H
