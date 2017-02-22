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
		std::vector<Node> solution;
		bool isRepeat(Node n);
	public:
		UCS(state st);
		void search();
};

#endif
