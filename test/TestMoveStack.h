#ifndef TestMoveStack_h
#define TestMoveStack_h
	#include "../src/MoveStack.h"
	#include "../src/Move.h"
	#include <iostream>

	using namespace std;

	class TestMoveStack : public MoveStack {
		public:
			bool matches(int board[]);
			int countBoardMoves(int board[]);
			void displayAsBoard();
			TestMoveStack();
			~TestMoveStack();
	};
#endif