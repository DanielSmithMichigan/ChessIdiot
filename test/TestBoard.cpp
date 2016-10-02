#ifndef TestBoard_cpp
#define TestBoard_cpp
	#include "TestBoard.h"

	TestBoard::TestBoard() 
		: Board() {
	}

	TestBoard::~TestBoard() {

	}

	bool TestBoard::matches(int board[]) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				if (board[xyToIntTestBoard(x, y)] != squares[xyToInt(x, y)]) {
					cout << "MISMATCH ON X: " << x << " Y: " << y << endl;
					cout << "EXPECTING: " << board[xyToIntTestBoard(x, y)] << endl;
					cout << "FOUND: " << squares[xyToInt(x, y)] << endl;
					return false;
				}
			}
		}
		return true;
	}
#endif