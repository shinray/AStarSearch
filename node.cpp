#include "node.h"

#include "state.h"

// Node::Node() {
	
// }

const int Node::cost = 1; // n-puzzle

// presumably this is a root node
Node::Node(state input) {
	depth = cost;
	parent = NULL;
	st = input;
	hcost = 0;
	fcost = hcost + cost;
}

Node::Node(state input, Node* p) {
	st = input;
	parent = p;
	depth = parent->getDepth() + cost;
	hcost = 0;
	fcost = hcost + cost;
}

// Node::~Node() {
	// see tree.cpp for destructor
	// nvm, maybe I don't want to use tree at all
	
// }

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
	std::vector<state> children = st.genChildren();
	
	//if (!child_list.empty()) child_list.clear();
	
	// for(unsigned i = 0; i < children.size(); i++)
	// {
		// child_list.push_back(&children[i]);
	// }
	
	return children;
}

bool Node::operator<(Node &aNode) {
	return (this->cost_() < aNode.cost_());
}

/*
void Node::append(state st) {
	state
	child_list.push_back()
}
*/
int Node::misplaced()
{
	hcost = st.misplaced();
	fcost = hcost + cost;
	return hcost;
}

int Node::manDist()
{
	hcost = st.manDist();
	fcost = hcost + cost;
	return hcost;
}

int Node::cost_()
{
	fcost = hcost + cost;
	return fcost;
}