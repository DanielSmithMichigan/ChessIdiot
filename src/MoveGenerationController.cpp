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
			Fen *fen = new Fen();
			cout << "FEN: " << fen->exportLegacyBoard() << endl;
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

	uint32_t MoveGenerationController::identifyMove(string input) {
		int from = boardCoordToInt(input.substr(0, 2));
		int to = boardCoordToInt(input.substr(2, 2));
		int piece = 0;
		if (input.length() == 5) {
			piece = getPieceFromLetter(input.substr(4, 1));
		}
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t moveFound;
		while (uint32_t currentMove = MoveStack::instance->pop()) {
			if (from == FROM(currentMove)
				&& to == TO(currentMove)
				&& piece == PIECE(currentMove)) {
				moveFound = currentMove;
				break;
			}
		}
		MoveStack::instance->reset();
		return moveFound;
	}

	void MoveGenerationController::printMoveStack() {
		cout << "Printing Move Stack" << endl;
		printMoveStackRecur(Board::currentState);
	}

	void MoveGenerationController::printMoveStackRecur(State *currentState) {
		if (currentState->prev) {
			printMoveStackRecur(currentState->prev);
		}
		cout << intToBoardCoord(FROM(currentState->move)) << intToBoardCoord(TO(currentState->move)) << endl;
	}

#endif