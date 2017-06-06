#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController *MoveGenerationController::instance = new MoveGenerationController();

	MoveGenerationController::MoveGenerationController() {
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::reset() {
		bestMove = 0;
		nodesSearched = 0;
		bestScore = INT32_MIN;
		depthSearched = 0;
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

	uint32_t MoveGenerationController::getBestMove(int depth) {
		reset();
		depthSearched = depth;
		generateAllMoves<false>();
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			nodesSearched++;
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::instance->increaseDepth();
			int score = -alphaBeta(INT16_MIN + 1, INT16_MAX, depth - 1);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
			if (score > bestScore) {
				bestScore = score;
				bestMove = currentMove;
			} 
		}

		return bestMove;
	}

	int MoveGenerationController::alphaBeta(int oldAlpha, int beta, int depthRemaining) {
		nodesSearched++;

		int alpha = oldAlpha;
		if (depthRemaining == 0) {
			// return Board::pieceValue;
			int result = quiescence(alpha, beta);
			TranspositionTable::instance->store(0,result,SCORE);
			return result;
		}

		int score = TranspositionTable::instance->searchScore(depthRemaining);
		if (score != TRANSPOSITION_TABLE_MISS) {
			return score;
		}
		generateAllMoves<false>();
		int legalMoves = 0;
		int bestCurrentMove = 0;
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			legalMoves++;
			MoveStack::instance->increaseDepth();
			int score = -alphaBeta(-beta, -alpha, depthRemaining - 1);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
			if (score >= beta) {
				return beta; 
			} else if (score > alpha) {
				alpha = score;
				bestCurrentMove = currentMove;
			}
		}

		if (legalMoves == 0) {
			return Evaluation::terminalPositionValue();
		}

		if (alpha != oldAlpha) {
			TranspositionTable::instance->store(bestCurrentMove,alpha,PRINCIPAL_VARIATION);
		}

		return alpha;
	}

	int MoveGenerationController::quiescence(int oldAlpha, int beta) {
		nodesSearched++;

		int alpha = oldAlpha;
		int positionValue = Board::pieceValue;
		if (positionValue >= beta) {
			return beta;
		} else if (positionValue > alpha) {
			alpha = positionValue;
		}
		int bestCurrentScore = INT32_MIN;
		int bestCurrentMove = 0;
		generateAllMoves<true>();
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::instance->increaseDepth();
			int score = -quiescence(-beta, -alpha);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
			if (score >= beta) {
				return beta; 
			} else if (score > alpha) {
				alpha = score;
				bestCurrentMove = currentMove;
			}
		}

		if (alpha != oldAlpha) {
			TranspositionTable::instance->store(bestCurrentMove,alpha, PRINCIPAL_VARIATION);
		} else {
			TranspositionTable::instance->store(0,alpha,SCORE);
		}

		return alpha;
	}

	void MoveGenerationController::showStats() {
		cout << "Depth: " << depthSearched
			 << " from: " << FROM(bestMove)
			 << " to: " << TO(bestMove)
			 << " score: " << bestScore
		     << " nodes: " << nodesSearched << endl;
	}

#endif