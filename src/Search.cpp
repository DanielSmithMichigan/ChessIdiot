#ifndef Search_cpp
#define Search_cpp
	#include "Search.h"

	Search *Search::instance = new Search();

	Search::Search() {
	}

	Search::~Search() {

	}

	void Search::reset() {
		bestMove = 0;
		nodesSearched = 0;
		bestScore = INT32_MIN;
		depthSearched = 0;
	}

	uint32_t Search::getBestMove(int depth) {
		reset();
		depthSearched = depth;
		MoveGenerationController::instance->generateAllMoves<false>();
		bestScore = INT32_MIN + 1;
		while(uint32_t currentMove = MoveStack::instance->pop()) {
			nodesSearched++;
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			MoveStack::instance->increaseDepth();
			int score = -alphaBeta(INT32_MIN + 1, -bestScore, depth - 1);
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
			if (score > bestScore) {
				bestScore = score;
				bestMove = currentMove;
			} 
		}

		TranspositionTable::instance->store(bestMove, bestScore, PRINCIPAL_VARIATION, depth);

		return bestMove;
	}

	uint32_t Search::iterativeDeepening(string fen, int maxDepth) {
		int currentDepth = 1;
		uint32_t bestMove;
		while(true) {
			if (currentDepth > maxDepth) {
				return bestMove;
			}
			Fen::import(fen);
			MoveStack::instance->reset();
			bestMove = getBestMove(currentDepth++);
			showStats();
		}
		return bestMove;
	}

	int Search::alphaBeta(int oldAlpha, int beta, int depthRemaining) {
		int alpha = oldAlpha;

		int hashScore;
		if (TranspositionTable::instance->searchPosition(depthRemaining, alpha, beta, hashScore)) {
			return hashScore;
		}

		if (depthRemaining == 0) {
			int result = quiescence(alpha, beta);
			return result;
		}

		if (Board::currentState->depth >= DEPTH_LIMIT) {
			return quiescence(alpha, beta);
		}

		nodesSearched++;
		MoveGenerationController::instance->generateAllMoves<false>();
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
				TranspositionTable::instance->store(bestCurrentMove, beta, LOWER_BOUND, depthRemaining);
				if (!Board::piecesIndex[TO(currentMove)]) {
					MoveStack::instance->markKiller(currentMove);
				}
				return beta; 
			} else if (score > alpha) {
				if (!Board::piecesIndex[TO(currentMove)]) {
					MoveStack::instance->markHistory(currentMove);
				}
				alpha = score;
				bestCurrentMove = currentMove;
			}
		}

		if (legalMoves == 0) {
			return Evaluation::terminalPositionValue();
		}

		if (alpha != oldAlpha) {
			TranspositionTable::instance->store(bestCurrentMove, alpha, PRINCIPAL_VARIATION, depthRemaining);
		} else {
			TranspositionTable::instance->store(bestCurrentMove, alpha, UPPER_BOUND, depthRemaining);
		}

		return alpha;
	}

	int Search::quiescence(int oldAlpha, int beta) {
		nodesSearched++;

		int alpha = oldAlpha;
		int positionValue = Evaluation::positionValue();
		if (positionValue >= beta) {
			return beta;
		} else if (positionValue > alpha) {
			alpha = positionValue;
		}

		if (Board::currentState->depth >= DEPTH_LIMIT) {
			return positionValue;
		}
		int bestCurrentScore = INT32_MIN;
		int bestCurrentMove = 0;
		MoveGenerationController::instance->generateAllMoves<true>();
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
			TranspositionTable::instance->store(bestCurrentMove, alpha, PRINCIPAL_VARIATION, 0);
		}

		return alpha;
	}

	void Search::showStats() {
		cout << "info score cp " << bestScore << " depth " << depthSearched << " nodes " << (nodesSearched / 1000) << " pv ";
		showPv();
		cout << endl;
	}

	void Search::showPv() {
		if (Board::currentState->depth >= 20) {
			return;
		}
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t pvMove = TranspositionTable::instance->searchMove();
		bool found = false;
		while (uint32_t currentMove = MoveStack::instance->pop()) {
			if (currentMove == pvMove) {
				found = true;
			} 
		}
		if (found) {
			cout << "" << intToBoardCoord(FROM(pvMove)) << intToBoardCoord(TO(pvMove)) << " ";
			Board::doMove(pvMove);
			MoveStack::instance->increaseDepth();
			showPv();
			MoveStack::instance->decreaseDepth();
			Board::undoMove();
		}
	}
#endif