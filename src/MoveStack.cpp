#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	MoveStack::MoveStack() {
		for(int i = 0; i < MAX_DEPTH; i++) {
			stack[i] = 0;
		}
	}

	MoveStack::~MoveStack() {

	}

	void MoveStack::push(uint32_t move) {
		stack[top] = move;
		depthLimits[currentDepth] = top;
		top++;
	}

	void MoveStack::increaseDepth() {
		currentDepth++;
	}
	void MoveStack::decreaseDepth() {
		currentDepth--;
	}
#endif