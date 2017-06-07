#ifndef MoveStack_cpp
#define MoveStack_cpp
	#include "MoveStack.h"

	MoveStack *MoveStack::instance = new MoveStack();

	int mvvLva[7][7];
	int pieceValue[7] = {
		0,
		100,
		200,
		300,
		400,
		500,
		600
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
		searchHistory[Board::piecesIndex[FROM(move)]][TO(move)] += Board::currentState->depth;
	}

	void MoveStack::reset() {
		for (int victim = 0; victim < 7; victim++) {
			for (int attacker = 0; attacker < 7; attacker++) {
				mvvLva[victim][attacker] = pieceValue[victim] + 6 - (pieceValue[attacker] / 100) + 1000000;
			}
		}
		for (int i = 0; i < 7; i++) {
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
				stack[i].score = 2000000;
			}
		}
	}

	void MoveStack::push(uint32_t move) {
		uint32_t to = TO(move);
		uint32_t from = FROM(move);
		if (Board::piecesIndex[to]) {
			stack[top].score = mvvLva[Board::piecesIndex[to]][Board::piecesIndex[from]];
		} else if (move == searchKillers[Board::currentState->depth][0]) {
			stack[top].score = 900000;
		} else if (move == searchKillers[Board::currentState->depth][1]) {
			stack[top].score = 800000;
		} else {
			stack[top].score = searchHistory[Board::piecesIndex[from]][to];
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