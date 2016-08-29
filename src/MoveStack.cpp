#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	MoveStack::MoveStack() {
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