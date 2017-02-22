#include "state.h"

const std::vector<char> state::goal0 = {
		'1','2','3',
		'4','5','6',
		'7','8','0'};
const std::vector<char> state::goal1 = {
		'1','2','3',
		'4','0','5',
		'6','7','8'};

//default constructor
state::state() {
	board = {
		'7','0','5',
		'6','4','3',
		'2','1','8'};
	return;
}

// constructor
state::state(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth) {
	board[0] = first;
	board[1] = second;
	board[2] = third;
	board[3] = fourth;
	board[4] = fifth;
	board[5] = sixth;
	board[6] = seventh;
	board[7] = eighth;
	board[8] = ninth;
	return;
}

// overloaded constructor (vector)
state::state(std::vector<char> positions) {
	board = positions;
	return;
}

// sets a specific state
void state::setState(char first, char second, char third,
				char fourth, char fifth, char sixth,
				char seventh, char eighth, char ninth) {
	board[0] = first;
	board[1] = second;
	board[2] = third;
	board[3] = fourth;
	board[4] = fifth;
	board[5] = sixth;
	board[6] = seventh;
	board[7] = eighth;
	board[8] = ninth;
	return;
}

// overloaded assignment function
void state::setState(std::vector<char> positions) {
	board = positions;
	return;
}

// assignment, for a specific index
void state::set(char val, int index) {
	board[index] = val;
	return;
}

// returns the state in the form of a char vector
std::vector<char> state::getState() {
	return board;
}

// sets the state to an arbitrary "default" position
void state::reset(){
	board = {
	'1','2','3',
	'4','5','6',
	'7','8','0'};
	return;
}

// returns the index of the "hole" in an n-puzzle
int state::getHole() {
	int ret = -1;
	for(int i = 0; i < 9; i++)
	{
		if (board[i] == '0') ret = i;
	}
	
	return ret;
}

// swaps the values at the indices 'first' and 'second', stores
// it in a vector supplied
void state::swap(int first, int second, std::vector<state> &ret) {
	std::vector<char> tmp = getState();
	std::iter_swap(tmp.begin() + first, tmp.begin() + second);
	state newstate = state(tmp);
	ret.push_back(newstate);
	return;
}

std::ostream& state::operator<< (std::ostream &out, const state &st)
{
	out << board[0] << ' ' << board[1] << ' ' << board[2] << '\n';
	out << board[3] << ' ' << board[4] << ' ' << board[5] << '\n';
	out << board[6] << ' ' << board[7] << ' ' << board[8] << '\n';
}

// generates a vector of valid child states
std::vector<state> state::genChildren() {
	std::vector<state> ret;
	int hole = getHole();
	
	if (hole != 0 && hole != 3 && hole != 6) {
		//hole -1
		swap(hole-1,hole,ret);
	}
	
	if (hole != 6 && hole != 7 && hole != 8)
	{
		swap(hole + 3, hole, ret);
	}
	
	if (hole != 0 && hole != 1 && hole != 2)
	{
		swap(hole - 3, hole, ret);
	}
	
	if (hole != 2 && hole != 5 && hole != 8)
	{
		swap(hole + 1, hole, ret);
	}
	
	return ret;
}

// exactly what it says on the tin
bool state::isGoal() {
	bool ret = false;
	
	if (board == goal0) return true;
	//if (board == goal1) return true;
	
	return ret;
}
