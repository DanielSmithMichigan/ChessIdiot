#ifndef TestUtility_h
#define TestUtility_h
	#include "../src/MoveGenerationController.h"
	#include "../src/MoveStack.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <stdint.h>
	void assertMoveExists(string fenString) {
		bool found = false;
		Fen* fen = new Fen();
		MoveGenerationController::generateAllMoves();
		while (uint32_t currentMove = MoveStack::pop()) {
			Board::doMove(currentMove);
			if (fen->getBoardSquares().compare(fenString) == 0) {
				found = true;
			}
			Board::undoMove();
		}
		ASSERT_TRUE(found) << fenString << " should be an available move.";
	}
#endif