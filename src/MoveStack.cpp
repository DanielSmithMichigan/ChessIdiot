#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	static int mvvLva[13][13];
	static int pieceValue[13] = {
		0,
		1,
		3,
		3,
		5,
		9,
		5,
		1,
		3,
		3,
		5,
		9,
		5
	};

	static bool sortByMVVLVA(uint32_t a, uint32_t b) {

		int capturedA = CAPTURED_PIECE(a);
		int aValue = capturedA ? mvvLva[capturedA][Board::squares[FROM(a)]] : 0;

		int capturedB = CAPTURED_PIECE(b);
		int bValue = capturedB ? mvvLva[capturedB][Board::squares[FROM(b)]] : 0;

		return aValue < bValue;
	}

	MoveStack::MoveStack(shared_ptr<Board> board) : board(board) {
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				mvvLva[i][j] = (100 * pieceValue[i]) - pieceValue[j];
			}
		}
		reset();
	}

	MoveStack::~MoveStack() {

	}

	void MoveStack::reset() {
		for(int i = 0; i < MOVE_STACK_LIMIT; i++) {
			stack[i] = 0;
		}
		for(int i = 0; i < DEPTH_LIMIT; i++) {
			depthLimits[i] = 0;
		}
		top = 0;
		currentDepth = 0;
	}

	void MoveStack::push(uint32_t move) {
		stack[top++] = move;
		depthLimits[currentDepth] = top;
	}

	int MoveStack::getMovesRemaining() {
		return top - getDepthBottom();
	}

	uint32_t MoveStack::pop() {
		if (top <= getDepthBottom()) {
			return 0;
		}
		depthLimits[currentDepth] = --top;
		return stack[top];
	}

	void MoveStack::sortCurrentDepth() {
		sort(stack+getDepthBottom(), 
			 stack+top, 
			 &sortByMVVLVA);
	}

	void MoveStack::increaseDepth() {
		currentDepth++;
		depthLimits[currentDepth] = top;
	}

	void MoveStack::decreaseDepth() {
		currentDepth--;
		top = depthLimits[currentDepth];
	}

	int MoveStack::getDepthBottom() {
		if (currentDepth == 0) {
			return 0;
		}
		return depthLimits[currentDepth - 1];
	}
#endif