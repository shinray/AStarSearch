#include "node.h"

// Node::Node() {
	
// }

const int Node::cost = 1; // n-puzzle

// presumably this is a root node
Node::Node(state input) {
	depth = cost;
	parent = NULL;
	st = input;
}

Node::Node(state input, Node* p) {
	st = input;
	parent = p;
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

Node* Node::getParent() {
	return parent;
}

std::vector<state> Node::genChild(){
	std::vector<state> children = st.genChild();
	
	if (!child_list.empty()) child_list.clear();
	
	for(int i = 0; i < children.size(); i++)
	{
		child_list.push_back(&children[i]);
	}
	
	return children;
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
