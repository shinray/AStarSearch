#include "node.h"

// Node::Node() {
	
// }

const int Node::cost = 1; // n-puzzle

// presumably this is a root node
Node::Node(state input) {
	depth = cost;
}

Node::Node(state input, Node* parent) {
	depth = parent->getDepth() + cost;
}

Node::~Node() {
	// see tree.cpp for destructor
	// nvm, maybe I don't want to use tree at all
	
}

state Node::getState() {
	return st;
}

void Node::editState(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth) {
	st.setState(first, second, third,
				fourth, fifth, sixth,
				seventh, eighth, ninth);
}

void Node::editState(std::vector<char> v) {
	st.setState(v);
}

int Node::getDepth() {
	return depth;
}

bool Node::operator<(Node &aNode) {
	return (this->getDepth() < aNode.getDepth());
}

/*
void Node::append(state st) {
	state
	child_list.push_back()
}
*/