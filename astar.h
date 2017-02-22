#ifndef ASTAR_H
#define ASTAR_H

#include "node.h"

class AStar {
	private:
		Node root;
		bool isRepeat(Node n);
	public:
		AStar(state st);
		void search();
};

#endif