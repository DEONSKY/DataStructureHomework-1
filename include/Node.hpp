
#ifndef NODE_HPP
#define NODE_HPP
#include "NULL.hpp"


class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(const int& , Node*  , Node* );
};
#endif