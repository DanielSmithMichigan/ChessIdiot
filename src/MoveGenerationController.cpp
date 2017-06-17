#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController *MoveGenerationController::instance = new MoveGenerationController();

	MoveGenerationController::MoveGenerationController() {
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::runAtDepth(uint64_t depth, void (*fn)()) {
		if (depth == 0) {
			fn();
			return;
		}
		generateAllMoves<false>();
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::instance->increaseDepth();
			runAtDepth(depth - 1, fn);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
		}
	}

	uint64_t MoveGenerationController::countMovesAtDepth(uint64_t depth) {
		if (depth == 0) {
			return 1;
		}
		generateAllMoves<false>();
		uint64_t counter = 0;
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::instance->increaseDepth();
			counter += countMovesAtDepth(depth - 1);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
		}
		return counter;
	}

#endif