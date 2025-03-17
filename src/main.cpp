import fmt;

#include "template.hpp"

int main() {
	Node* head = new Node(0);
	head->left = new Node(1);
	head->left->left = new Node(2);
	head->right = new Node(3);
	head->right->right = new Node(4);
	traverse(head, &Node::left, &Node::right);
	return 0;
}
