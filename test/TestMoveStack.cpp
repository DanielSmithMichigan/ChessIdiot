#ifndef TestMoveStack_cpp
#define TestMoveStack_cpp
	#include "TestMoveStack.h"

	TestMoveStack::TestMoveStack(shared_ptr<Board> board) 
		: MoveStack(board) {
	}

	TestMoveStack::~TestMoveStack() {

	}

	int TestMoveStack::countBoardMoves(int board[]) {
		int moveCount = 0;
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i]) {
				moveCount += board[i];
			}
		}
		return moveCount;
	}

	void TestMoveStack::displayAsBoard() {
		int board[BOARD_SIZE];
		for (int i = 0; i < BOARD_SIZE; i++) {
			board[i] = EMPTY_SPACE;
		}
		for (int i = 0; i < top; i++) {
			cout << TO(stack[i]) << endl;
			board[TO(stack[i])] = WHITE_PAWN;
		}
		for (int y = 0; y < BOARD_WIDTH; y++) {
			for (int x = 0; x < BOARD_WIDTH; x++) {
				if (board[x + ROWS(y)]) {
					cout << "X";
				} else {
					cout << "0";
				}
				cout << " ";
			}
			cout << endl;
		}
	}

	bool TestMoveStack::matches(int board[]) {
		int moveCount = countBoardMoves(board);
		if (top != moveCount) {
			displayAsBoard();
			cout << "MOVECOUNT MISMATCH. Top: " << top << " MoveCount: " << moveCount << endl;
			return false;
		}
		for (int i = 0; i < top; i++) {
			int to = TO(stack[i]);
			if (board[to] <= 0) {
				cout << "MOVE EXISTS AT: " << to << endl;
				displayAsBoard();
				return false;
			}
			board[to]--;
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