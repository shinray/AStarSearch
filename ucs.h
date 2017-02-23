#ifndef UCS_H
#define UCS_H

#include <queue> // std::priority_queue
//#include "state.h" possibly unnecessary
#include "node.h"
#include "state.h"
//#include <unordered_set> // unordered_set

class UCS
{
	private:
		//Node root;
		//std::priority_queue<Node> stack;
		//std::queue<Node*> q;
		std::priority_queue<Node*, std::vector<Node*>,std::greater<Node*>> q;
		std::vector<Node> solution;
		//std::unordered_set<state> explored;
		std::vector<state> explored;
		bool isRepeat(Node n);
		std::vector<Node*> nodelist;
	public:
		UCS(state st);
		virtual ~UCS();
		void search();
};

#endif
