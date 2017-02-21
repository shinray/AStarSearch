#ifndef UCS_H
#define UCS_H

#include <queue> // std::priority_queue
//#include "state.h" possibly unnecessary
#include "node.h"

class UCS
{
	private:
		Node root;
		std::priority_queue<Node> stack;
	public:
		UCS(state st);
		void search(std::priority_queue<Node> s);
};

#endif