#ifndef Search_cpp
#define Search_cpp
	#include "Search.h"

	Search *Search::instance = new Search();

	Search::Search() {

	}

	Search::~Search() {

	}

	void Search::timeRemaining(int msRemaining) {
		stopTime = getCurrentTimeMs() + (msRemaining / 30);
	}

	void Search::checkStopped() {
		if (getCurrentTimeMs() > stopTime) {
			stopped = true;
		}
	}

	void Search::clearForSearch() {
		stopped = false;
		stopTime = INT32_MAX;
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

			if (stopped) {
				return 0;
			}

			if (score > bestScore) {
				bestScore = score;
				bestMove = currentMove;
			} 
		}

		TranspositionTable::instance->store(bestMove, bestScore, EXACT, depth);

		return bestMove;
	}

	uint32_t Search::iterativeDeepening(string fen, int maxDepth) {
		int currentDepth = 1;
		uint32_t output, bestMoveCurrentDepth;
		while(true) {
			if (currentDepth > maxDepth) {
				return output;
			}
			Fen::import(fen);
			MoveStack::instance->reset();
			bestMoveCurrentDepth = getBestMove(currentDepth++);
			if (stopped) {
				return output;
			}
			if (bestMoveCurrentDepth != 0) {
				output = bestMoveCurrentDepth;
			}
			showStats();
		}
		return output;
	}

	int Search::alphaBeta(int oldAlpha, int beta, int depthRemaining) {
		int alpha = oldAlpha;

		int hashScore = INT32_MIN;

		if (TranspositionTable::instance->searchPosition(depthRemaining, alpha, beta, hashScore)) {
			return hashScore;
		}

		if ((nodesSearched & 2047) == 0) {
			checkStopped();
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
		int bestCurrentScore = INT32_MIN;
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

			if (stopped) {
				return 0;
			}

			if (score > bestCurrentScore) {
				bestCurrentScore = score;
				if (score >= beta) {
					TranspositionTable::instance->store(bestCurrentMove, beta, BETA, depthRemaining);
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
		}

		if (legalMoves == 0) {
			return Evaluation::terminalPositionValue();
		}

		if (alpha != oldAlpha) {
			TranspositionTable::instance->store(bestCurrentMove, bestCurrentScore, EXACT, depthRemaining);
		} else {
			TranspositionTable::instance->store(bestCurrentMove, alpha, ALPHA, depthRemaining);
		}

		return alpha;
	}

	int Search::quiescence(int oldAlpha, int beta) {
		nodesSearched++;

		if ((nodesSearched & 2047) == 0) {
			checkStopped();
		}

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

			if (stopped) {
				return 0;
			}

			if (score >= beta) {
				return beta; 
			} else if (score > alpha) {
				alpha = score;
				bestCurrentMove = currentMove;
			}
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