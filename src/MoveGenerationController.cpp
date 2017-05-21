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
		MoveStack::sortCurrentDepth();
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



	uint32_t MoveGenerationController::getBestMove(int depth) {
		generateAllMoves();
		int bestScore = INT32_MIN;
		int bestMove = 0;
		while(uint32_t currentMove = MoveStack::pop()) {
			cout << "FROM: " << FROM(currentMove)
				 << " TO: " << TO(currentMove) << endl;
			Board::doMove(currentMove);
			if (canTakeKing()) {
				cout << "ILLEGAL MOVE" << endl;
				Board::undoMove();
				continue;
			}
			MoveStack::increaseDepth();
			int score = -alphaBeta(INT16_MIN + 1, INT16_MAX, depth - 1);
			MoveStack::decreaseDepth();
			Board::undoMove();
			if (score > bestScore) {
				bestScore = score;
				bestMove = currentMove;
			} 
		}
		return bestMove;
	}

	int MoveGenerationController::alphaBeta(int alpha, int beta, int depthRemaining) {
		if (depthRemaining == 0) {
			cout << "SCORE: " << Board::pieceValue << endl;
			return Board::pieceValue;
		}
		generateAllMoves();
		int legalMoves = 0;
		while(uint32_t currentMove = MoveStack::pop()) {
			cout << "FROM: " << FROM(currentMove)
				 << " TO: " << TO(currentMove) << endl;
			Board::doMove(currentMove);
			if (canTakeKing()) {
				cout << "ILLEGAL MOVE" << endl;
				Board::undoMove();
				continue;
			}
			legalMoves++;
			MoveStack::increaseDepth();
			int score = -alphaBeta(INT16_MIN + 1, INT16_MAX, depthRemaining - 1);
			MoveStack::decreaseDepth();
			Board::undoMove();
			if (score >= beta) {
				return beta; 
			} else if (score > alpha) {
				alpha = score;
			}
		}

		if (legalMoves == 0) {
			return Evaluation::terminalPositionValue();
		}

		return alpha;
	}

#endif