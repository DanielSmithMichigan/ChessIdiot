	#include "RookMoveGenerator.h"

	RookMoveGeneratorTest::RookMoveGeneratorTest() {
		moveStack.reset(new TestMoveStack());
		board.reset(new Board());
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
	}

	RookMoveGeneratorTest::~RookMoveGeneratorTest() {
	}

	TEST_F(RookMoveGeneratorTest, RookInMiddle) {
		board->place(WHITE_ROOK, 51);
		moveGenerationController->generateMovesAt(51);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(RookMoveGeneratorTest, WillNotTakeWhitePiece) {
		board->place(WHITE_ROOK, 51);
		board->place(WHITE_ROOK, 53);
		moveGenerationController->generateMovesAt(51);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(RookMoveGeneratorTest, WillTakeBlackPiece) {
		board->place(WHITE_ROOK, 51);
		board->place(BLACK_ROOK, 53);
		moveGenerationController->generateMovesAt(51);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}