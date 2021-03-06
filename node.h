#ifndef NODE_H
#define NODE_H

//#include <vector>
#include "state.h"

class Node
{
	private:
		Node* parent;
		//std::vector<Node*> child_list;
		state st;
		int depth;
		static const int cost; // now that's a virtual tongue twister
		int hcost; //heuristic
		int fcost; //total cost for a*
	public:
		//Node();
		Node(state input);
		Node(state input, Node* parent);
		// virtual ~Node();
		state getState();
		void editState(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth);
		void editState(std::vector<char> v);
		int getDepth();
		Node* getParent();
		std::vector<state> genChild();
		bool operator<(const Node &aNode) const;
		bool operator>(const Node &aNode) const;
		//void append(state st);
		//int pathcost();
		int misplaced();
		int manDist();
		int cost_() const;
		int hcost_() const;
};

#endif
