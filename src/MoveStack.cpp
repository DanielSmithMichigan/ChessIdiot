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
	}

	void MoveStack::push(uint32_t move) {
		stack[top] = move;
		depthLimits[currentDepth] = top++;
	}

	void MoveStack::increaseDepth() {
		depthLimits[top] = depthLimits[currentDepth] + 1;
		currentDepth++;
	}
	void MoveStack::decreaseDepth() {
		currentDepth--;
		top = depthLimits[currentDepth];
	}
#endif