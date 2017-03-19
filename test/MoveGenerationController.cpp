	#include "MoveGenerationController.h"

	MoveGenerationControllerTest::MoveGenerationControllerTest() {
		moveStack.reset(new MoveStack());
		board.reset(new Board());
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
		fen.reset(new Fen(board));
	}

	MoveGenerationControllerTest::~MoveGenerationControllerTest() {
	}

	TEST_F(MoveGenerationControllerTest, GetPieceValue) {
		fen->import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		uint32_t bestMove = 0;
		int positionValue = moveGenerationController->alphaBeta(INT_MIN + 1, INT_MAX, 0, bestMove);
		ASSERT_EQ(positionValue, 0);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPiece) {
		fen->import("rnbqkbnr/pppppp1p/8/6p1/5P2/8/PPPPP1PP/RNBQKBNR w KQkq - 0 1");
		uint32_t bestMove = 0;
		int positionValue = moveGenerationController->alphaBeta(INT_MIN + 1, INT_MAX, 1, bestMove);
		ASSERT_EQ(FROM(bestMove), 69);
		ASSERT_EQ(TO(bestMove), 54);
		ASSERT_EQ(positionValue, 1);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPieceTwo) {
		fen->import("4k3/7p/8/8/8/8/8/7R w KQkq - 0 1");
		uint32_t bestMove = 0;
		int positionValue = moveGenerationController->alphaBeta(INT_MIN + 1, INT_MAX, 1, bestMove);
		ASSERT_EQ(FROM(bestMove), 119);
		ASSERT_EQ(TO(bestMove), 23);
	}

	TEST_F(MoveGenerationControllerTest, CanLookTwoMovesAhead) {
		fen->import("8/7p/8/7K/8/8/8/7k w - - 0 1");
		uint32_t bestMove = 0;
		int positionValue = moveGenerationController->alphaBeta(INT_MIN + 1, INT_MAX, 3, bestMove);
		ASSERT_EQ(FROM(bestMove), 55);
		ASSERT_EQ(TO(bestMove), 39);
	}