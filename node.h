#ifndef NODE_H
#define NODE_H
#include <QPoint>
#include <QList>
#include <QColor>

class Node {
	private:
	QRgb m_key;
	QList<QPoint> m_point_list;
	int m_height;

	public:
	Node();
	Node(QRgb key);
	~Node();

	Node* m_left;
	Node* m_right;
	
	QRgb key() const;
	int height() const;

	void set_key(const QRgb key);
	void set_height(const int height);
	QList<QPoint>& list();
};
#endif //NODE_H
