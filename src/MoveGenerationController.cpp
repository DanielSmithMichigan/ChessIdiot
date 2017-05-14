#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController::MoveGenerationController() {
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::generateAllMoves() {
		if (Board::turn == WHITE) {
			generatePawnMoves<WHITE, false>();
			generateBishopMoves<WHITE, false>();
			generateRookMoves<WHITE, false>();
		} else {
			generatePawnMoves<BLACK, false>();
			generateBishopMoves<BLACK, false>();
			generateRookMoves<BLACK, false>();
		}
	}

#endif