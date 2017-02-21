#include "node.h"

Node::Node() {
	
}

Node::Node(state input) {
	
}

Node::Node(state input, Node* parent) {
	
}

Node::~Node() {
	// see tree.cpp for destructor
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

/*
void Node::append(state st) {
	state
	child_list.push_back()
}
*/