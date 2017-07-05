#include "ChessPuzzle.h"

	ChessPuzzleTest::ChessPuzzleTest() {
		Init::instance->execute(true);
	}

	ChessPuzzleTest::~ChessPuzzleTest() {
	}

	TEST_F(ChessPuzzleTest, MultiplePuzzles) {
		uint32_t bestMove;
		Init::instance->reset();
		Fen::import("5k2/5rpB/pN1b2Q1/1p6/3P1qp1/P1P3PP/1P6/R6K b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "f4");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "f3");


		Init::instance->reset();
		Fen::import("8/8/RP6/2q5/K1Bk4/3P4/8/8 b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "d4");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "c3");


		Init::instance->reset();
		Fen::import("6k1/6p1/1p2b2p/1Pb1p3/2PqP2B/p2P2KP/Q7/5B2 b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "d4");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "e3");


		Init::instance->reset();
		Fen::import("5rk1/ppp3pp/3b2q1/P7/4p3/2P1B2K/2P1QP2/R4R2 b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "f8");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "f3");


		Init::instance->reset();
		Fen::import("8/3k4/6R1/2B5/1PP3p1/r6n/8/5K2 b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "a3");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "a1");


		Init::instance->reset();
		Fen::import("r1r5/p1Qbkppp/5n2/8/8/q2R1NP1/P3PPBP/6K1 w - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "c7");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "e5");


		Init::instance->reset();
		Fen::import("r1b3k1/q5bp/pp2N1p1/3p2N1/1P4n1/P3B3/5Q1P/5RK1 w - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "f2");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "f8");


		Init::instance->reset();
		Fen::import("1r1q2k1/p2pRpnp/1pp2bp1/3B4/3P1QP1/2P5/PP1B1P1P/7K b - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "f6");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "e7");


		Init::instance->reset();
		Fen::import("r1b3k1/q5N1/pp4p1/3p2Np/1P5Q/P3n3/7P/5RK1 w - -");
		bestMove = Search::instance->iterativeDeepening(8);
		ASSERT_EQ(intToBoardCoord(FROM(bestMove)), "f1");
		ASSERT_EQ(intToBoardCoord(TO(bestMove)), "f7");
	}