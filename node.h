#ifndef NODE_H
#define NODE_H
class Node {
	private:
	int m_value;

	int m_height;

	public:
	Node* m_left;
	Node* m_right;

	Node();
	Node(const int value);
	~Node();

	int value() const;
	int height() const;

	void set_value(const int value);
	void set_height(const int height);

};
#endif //NODE_H
