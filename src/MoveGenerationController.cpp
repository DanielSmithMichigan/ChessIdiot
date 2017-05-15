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
			generateQueenMoves<WHITE, false>();
			generateKnightMoves<WHITE, false>();
			generateKingMoves<WHITE, false>();
		} else {
			generatePawnMoves<BLACK, false>();
			generateBishopMoves<BLACK, false>();
			generateRookMoves<BLACK, false>();
			generateQueenMoves<BLACK, false>();
			generateKnightMoves<BLACK, false>();
			generateKingMoves<BLACK, false>();
		}
	}

#endif