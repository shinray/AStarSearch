#ifndef ASTAR_H
#define ASTAR_H

class AStar {
	private:
		Node root;
		bool isRepeat(Node n);
	public:
		AStar(state st);
		void search();
};

#endif
