#include "ucs.h"

UCS::UCS(state st) {
	root = Node(st);
	stack.push(root);
	search(stack);
}

void UCS::search(std::priority_queue<Node> s) {
	while(!s.empty()) {
		Node tmp = s.top();
		
		if (!tmp.getState().isGoal()) {
			
		}
	}
}