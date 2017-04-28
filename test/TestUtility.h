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
	void assertNotMoveExists(string fenString) {
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
		ASSERT_FALSE(found) << fenString << " should not be an available move.";
	}
	void showAllMoves() {
		Fen* fen = new Fen();
		MoveGenerationController::generateAllMoves();
		while (uint32_t currentMove = MoveStack::pop()) {
			Board::doMove(currentMove);
			cout << fen->getBoardSquares() << endl;
			Board::undoMove();
		}
	}
	void assertMoveCount(int assertedAmount) {
		int moveCount = 0;
		Fen* fen = new Fen();
		MoveGenerationController::generateAllMoves();
		while (uint32_t currentMove = MoveStack::pop()) {
			moveCount++;
		}
		ASSERT_EQ(moveCount, assertedAmount) << "Should have generated the expected number of moves" << endl;
	}
#endif