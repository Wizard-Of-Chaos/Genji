#ifndef NODE_H
#define NODE_H
#include <QPoint>
class Node {
	private:
	int m_value;
	QPoint(int xpos, int ypos) point;

	int m_height;

	public:
	Node* point;
	Node* m_left;
	Node* m_right;

	Node();
	Node(const int value);
	~Node();

	int value() const;
	int height() const;

	void set_value(const int value);
	void set_height(const int height);
	void set_point(const QPoint point);

};
#endif //NODE_H
