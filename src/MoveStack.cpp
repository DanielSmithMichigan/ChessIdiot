#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	MoveStack *MoveStack::instance = new MoveStack();

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


	MoveStack::MoveStack() {
		reset();
	}

	MoveStack::~MoveStack() {

	}

	void MoveStack::markKiller(uint32_t move) {
		searchKillers[Board::currentState->depth][1] = searchKillers[Board::currentState->depth][0];
		searchKillers[Board::currentState->depth][0] = move;
	}

	void MoveStack::markHistory(uint32_t move) {
		searchHistory[FROM(move)][TO(move)] += Board::currentState->depth * Board::currentState->depth;
	}

	void MoveStack::reset() {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				mvvLva[i][j] = (100 * pieceValue[i]) - pieceValue[j];
			}
		}
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				searchHistory[i][j] = 0;
			}
		}
		for(int i = 0; i < MOVE_STACK_LIMIT; i++) {
			stack[i] = WeightedMove(0, 0);
		}
		for(int i = 0; i < DEPTH_LIMIT; i++) {
			depthLimits[i] = 0;
			searchKillers[i][0] = 0;
			searchKillers[i][1] = 0;
		}
		top = 0;
		currentDepth = 0;
	}

	void MoveStack::scoreSpecialMoves(uint32_t move) {
		for (uint32_t i = getDepthBottom(); i < top; i++) {
			if (stack[i].move == move) {
				stack[i].score = 1000000;
			} else if (stack[i].move == searchKillers[Board::currentState->depth][0]) {
				stack[i].score = 900000;
			} else if (stack[i].move == searchKillers[Board::currentState->depth][1]) {
				stack[i].score = 800000;
			}
		}
	}

	void MoveStack::push(uint32_t move) {
		uint32_t to = TO(move);
		if (Board::piecesIndex[to]) {
			uint32_t from = FROM(move);
			stack[top].score = mvvLva[Board::piecesIndex[to]][Board::piecesIndex[from]];
		} else {
			stack[top].score = searchHistory[FROM(move)][TO(move)];
			stack[top].score = 0;
		}
		stack[top].move = move;
		top++;
		depthLimits[currentDepth] = top;
	}

	uint32_t MoveStack::pop() {
		uint32_t bottom = getDepthBottom();
		if (top <= bottom) {
			return 0;
		}
		int bestScoreFound = stack[bottom].score;
		int bestIndexFound = bottom;
		for (uint32_t i = bottom; i < top; i++) {
			if (stack[i].score > bestScoreFound) {
				bestScoreFound = stack[i].score;
				bestIndexFound = i;
			}
		}

		depthLimits[currentDepth] = --top;

		uint32_t bestMoveFound = stack[bestIndexFound].move;
		stack[bestIndexFound].move = stack[top].move;
		stack[bestIndexFound].score = stack[top].score;
		return bestMoveFound;
	}

	void MoveStack::increaseDepth() {
		currentDepth++;
		depthLimits[currentDepth] = top;
	}

	void MoveStack::decreaseDepth() {
		currentDepth--;
		top = depthLimits[currentDepth];
	}

	uint32_t MoveStack::getDepthBottom() {
		if (currentDepth == 0) {
			return 0;
		}
		return depthLimits[currentDepth - 1];
	}
#endif