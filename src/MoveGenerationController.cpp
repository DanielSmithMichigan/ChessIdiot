#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController::MoveGenerationController() {
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::generateAllMoves() {
		if (Board::turn == WHITE) {
			generatePawnMoves<WHITE>();
		} else {
			generatePawnMoves<BLACK>();
		}
	}

#endif