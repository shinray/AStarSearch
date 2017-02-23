#ifndef ASTAR_H
#define ASTAR_H

#include "node.h"
#include "state.h"
#include <queue> // std::priority_queue

class AStar {
	private:
		//Node root;
		bool isRepeat(Node n);
		std::priority_queue<Node*> q;
		std::vector<Node*> nodelist;
		std::vector<Node> solution;
	public:
		AStar(state st);
		virtual ~AStar();
		void search(int heuristic);
		// 0 for misplaced tile
		// 1 for manhattan distance
};

#endif
