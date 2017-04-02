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

	TEST_F(MoveGenerationControllerTest, WillTakeAPiece) {
		fen->import("rnbqkbnr/pppppp1p/8/6p1/5P2/8/PPPPP1PP/RNBQKBNR w KQkq - 0 1");
		int bestMove = moveGenerationController->getBestMove(1);
		ASSERT_EQ(FROM(bestMove), 69);
		ASSERT_EQ(TO(bestMove), 54);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPieceTwo) {
		fen->import("4k3/7p/8/8/8/8/8/7R w KQkq - 0 1");
		int bestMove = moveGenerationController->getBestMove(1);
		ASSERT_EQ(FROM(bestMove), 119);
		ASSERT_EQ(TO(bestMove), 23);
	}

	TEST_F(MoveGenerationControllerTest, CanLookTwoMovesAhead) {
		fen->import("8/7p/8/7K/8/8/8/7k w - - 0 1");
		int bestMove = moveGenerationController->getBestMove(3);
		ASSERT_EQ(FROM(bestMove), 55);
		ASSERT_EQ(TO(bestMove), 39);
	}

	TEST_F(MoveGenerationControllerTest, CanLookFiveMovesAhead) {
		fen->import("8/4K3/7p/8/8/8/8/8 w - - 0 1");
		int bestMove = moveGenerationController->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 20);
		ASSERT_EQ(TO(bestMove), 37);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzle) {
		fen->import("4kb1Q/pp2ppr1/3p3p/3P4/4q3/5nP1/P4PKP/2R5 w - - 0 1");
		int bestMove = moveGenerationController->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 7);
		ASSERT_EQ(TO(bestMove), 5);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzleTwo) {
		fen->import("r3r1k1/pp2n1pp/2p2p2/3p1q2/3P1P2/3Q1N2/PPP3PP/4RRK1 w - - 0 1");
		int bestMove = moveGenerationController->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 116);
		ASSERT_EQ(TO(bestMove), 20);
	}