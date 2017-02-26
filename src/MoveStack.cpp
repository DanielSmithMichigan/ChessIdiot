#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	MoveStack::MoveStack() {
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
	}

	uint32_t MoveStack::pop() {
		if (top <= getDepthBottom()) {
			return 0;
		}
		return stack[--top];
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