#ifndef STATE_H
#define STATE_H

#include <vector>
#include <algorithm> // iter_swap
#include <iostream> // ostream overloading

class state {
	private:
		std::vector<char> board(9);
		static const std::vector<char> goal0(9);
		static const std::vector<char> goal1(9);
		int getHole();
		void swap(int first, int second);
	public:
		state();
		state(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth);
		state(std::vector<char> positions);
		void setState(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth);
		void setState(std::vector<char> positions);
		void set(char val, int index);
		std::vector<char> getState();
		void reset();
		friend std::ostream& operator<< (std::ostream &out, const state &st);
		std::vector<state> genChildren();
		bool isGoal();
};

#endif
