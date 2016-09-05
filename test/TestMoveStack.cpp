#ifndef TestMoveStack_cpp
#define TestMoveStack_cpp
	#include "TestMoveStack.h"

	TestMoveStack::TestMoveStack() 
		: MoveStack() {
	}

	TestMoveStack::~TestMoveStack() {

	}

	bool TestMoveStack::matches(int board[]) {
		int moveCount = 0;
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i] == 1) {
				moveCount++;
			}
		}
		if (top != moveCount) {
			cout << "MOVECOUNT MISMATCH. Top: " << top << " MoveCount: " << moveCount << endl;
			return false;
		}
		for (int i = 0; i < top; i++) {
			int to = TO(stack[i]);
			if (board[to] != 1) {
				cout << "MOVE EXISTS AT: " << to << endl;
				return false;
			}
			board[to] = 0;
		}
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i] == 1) {
				cout << "BOARD HAS 1 AT: " << i << endl;
				return false;
			}
		}
		return true;
	}
#endif