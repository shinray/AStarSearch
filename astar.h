#ifndef ASTAR_H
#define ASTAR_H

#include "node.h"
#include "state.h"
#include <queue> // std::priority_queue
#include <cstdlib>


struct Compare
{
public:
    bool operator() (const Node* a, const Node* b) const
    {
        return (a->cost_() > b->cost_());
    }
};

//typedef std::priority_queue<Node*, std::vector<Node*>, Compare> nodeCompare;

class AStar {
	private:
		//Node root;
		bool isRepeat(Node n);
		// nodeCompare q;
		//std::priority_queue<Node*, std::vector<Node*>, Compare> q;
		std::priority_queue<Node*, std::vector<Node*>,Compare> q;
		std::vector<Node*> nodelist;
		std::vector<Node> solution;
		std::vector<state> explored;
	public:
		AStar(state st);
		virtual ~AStar();
		void search(int heuristic);
		// 0 for misplaced tile
		// 1 for manhattan distance
		void showSoln();
};

#endif
