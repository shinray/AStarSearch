#include "state.h"

const std::vector<char> state::goal0 = {
		'1','2','3',
		'4','5','6',
		'7','8','0'};
const std::vector<char> state::goal1 = {
		'1','2','3',
		'4','0','5',
		'6','7','8'};
		
std::ostream& operator<< (std::ostream &out, const state &st)
{
	out << st.board[0] << ' ' << st.board[1] << ' ' << st.board[2] << '\n' 
	<< st.board[3] << ' ' << st.board[4] << ' ' << st.board[5] << '\n' 
	<< st.board[6] << ' ' << st.board[7] << ' ' << st.board[8] << '\n';
	return out;
}

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

// number of misplaced tiles
int state::misplaced()
{
	int ret = 0;
	for(unsigned i = 0; i < board.size(), i++)
	{
		if (board[i] != goal0[i])
		{
			ret++;
		}
	}
	return ret;
}

// manhattan distance
int state::manDist() {
	int ret = 0;
	
	int index = 0;
	int val = -1;
	int col, row;
	//need to calculate every x,y coordinate
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			// first convert from char to int
			// then adjust by -1
			val = board[index] - '0' - 1; //off by 1
			
			// calculate supposed x-y coords
			// eg '1' = col:0, row:0
			// '8' = col:1, row:2
			if (val != -1) // not hole
			{
				// horizontal offset
				col = val % 3;
				// vertical offset
				row = val / 3;
				// manhattan formula: abs(y - y) + abs(x - x)
				ret += abs(row - (y)) + abs(col - (x));
			}
			
			index++;
		}
	}
	return ret;
}
