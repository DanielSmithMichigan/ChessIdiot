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

	uint64_t MoveGenerationController::countMovesAtDepth(uint64_t depth) {
		if (depth == 0) {
			return 1;
		}
		generateAllMoves();
		uint64_t counter = 0;
		while(uint32_t currentMove = MoveStack::pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::increaseDepth();
			counter += countMovesAtDepth(depth - 1);
			MoveStack::decreaseDepth();
			Board::undoMove();
		}
		return counter;
	}

	void MoveGenerationController::getAllFensAtDepth(uint64_t depth, vector<string> &fens) {
		if (depth == 0) {
			fens.push_back(Fen::exportLegacyBoard());
			return;
		}
		fens.push_back("BEGIN_BOARD");
		fens.push_back(Fen::exportLegacyBoard());
		fens.push_back("END_BOARD");
		generateAllMoves();
		while(uint32_t currentMove = MoveStack::pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::increaseDepth();
			getAllFensAtDepth(depth - 1, fens);
			MoveStack::decreaseDepth();
			Board::undoMove();
		}
	}

	void MoveGenerationController::logPath(uint64_t depth) {
		if (depth == 0) {
			cout << Fen::exportLegacyBoard() << endl;
			return;
		}
		cout << Fen::exportLegacyBoard() << endl;
		generateAllMoves();
		while(uint32_t currentMove = MoveStack::pop()) {
			// cout << currentMove << endl;
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::increaseDepth();
			logPath(depth - 1);
			MoveStack::decreaseDepth();
			Board::undoMove();
		}
	}

#endif