#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	int MoveStack::depthLimits[DEPTH_LIMIT] = {};
	uint32_t MoveStack::stack[MOVE_STACK_LIMIT] = {};
	int MoveStack::currentDepth = 0;
	int MoveStack::top = 0;

	int mvvLva[7][7];
	int pieceValue[7] = {
		0,
		1,
		3,
		3,
		5,
		9,
		5
	};

	bool sortByMVVLVA(uint32_t a, uint32_t b) {

		int capturedA = Board::piecesIndex[TO(a)];
		int aValue = capturedA ? mvvLva[capturedA][Board::piecesIndex[FROM(a)]] : 0;

		int capturedB = Board::piecesIndex[TO(b)];
		int bValue = capturedB ? mvvLva[capturedB][Board::piecesIndex[FROM(b)]] : 0;

		return aValue < bValue;
	}


	MoveStack::MoveStack() {
		reset();
	}

	MoveStack::~MoveStack() {

	}

	void MoveStack::reset() {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				mvvLva[i][j] = (100 * pieceValue[i]) - pieceValue[j];
			}
		}
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