	#include "PawnMoveGeneration.h"

	PawnMoveGeneratorTest::PawnMoveGeneratorTest() {
	}

	PawnMoveGeneratorTest::~PawnMoveGeneratorTest() {
	}

	void PawnMoveGeneratorTest::SetUp() {
		Board::reset();
	}

	TEST_F(PawnMoveGeneratorTest, OnePawnForwardWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/PPPPPPPP/8/8 w");
		assertMoveExists("8/8/8/8/P7/1PPPPPPP/8/8");
		assertMoveExists("8/8/8/8/1P6/P1PPPPPP/8/8");
		assertMoveExists("8/8/8/8/2P5/PP1PPPPP/8/8");
		assertMoveExists("8/8/8/8/3P4/PPP1PPPP/8/8");
		assertMoveExists("8/8/8/8/4P3/PPPP1PPP/8/8");
		assertMoveExists("8/8/8/8/5P2/PPPPP1PP/8/8");
		assertMoveExists("8/8/8/8/6P1/PPPPPP1P/8/8");
		assertMoveExists("8/8/8/8/7P/PPPPPPP1/8/8");
		assertMoveCount(8);
	}

	TEST_F(PawnMoveGeneratorTest, TwoPawnsForwardWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/8/PPPPPPPP/8 w");
		MoveGenerationController::generateAllMoves();
		assertMoveExists("8/8/8/8/8/P7/1PPPPPPP/8");
		assertMoveExists("8/8/8/8/8/1P6/P1PPPPPP/8");
		assertMoveExists("8/8/8/8/8/2P5/PP1PPPPP/8");
		assertMoveExists("8/8/8/8/8/3P4/PPP1PPPP/8");
		assertMoveExists("8/8/8/8/8/4P3/PPPP1PPP/8");
		assertMoveExists("8/8/8/8/8/5P2/PPPPP1PP/8");
		assertMoveExists("8/8/8/8/8/6P1/PPPPPP1P/8");
		assertMoveExists("8/8/8/8/8/7P/PPPPPPP1/8");
		assertMoveExists("8/8/8/8/P7/8/1PPPPPPP/8");
		assertMoveExists("8/8/8/8/1P6/8/P1PPPPPP/8");
		assertMoveExists("8/8/8/8/2P5/8/PP1PPPPP/8");
		assertMoveExists("8/8/8/8/3P4/8/PPP1PPPP/8");
		assertMoveExists("8/8/8/8/4P3/8/PPPP1PPP/8");
		assertMoveExists("8/8/8/8/5P2/8/PPPPP1PP/8");
		assertMoveExists("8/8/8/8/6P1/8/PPPPPP1P/8");
		assertMoveExists("8/8/8/8/7P/8/PPPPPPP1/8");
		assertMoveCount(16);
	}

	TEST_F(PawnMoveGeneratorTest, BlockersWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/2Q2q2/3Qq3/PPPPPPPP/8 w");
		assertMoveExists("8/8/8/8/P1Q2q2/3Qq3/1PPPPPPP/8");
		assertMoveExists("8/8/8/8/2Q2q2/P2Qq3/1PPPPPPP/8");
		assertMoveExists("8/8/8/8/1PQ2q2/3Qq3/P1PPPPPP/8");
		assertMoveExists("8/8/8/8/2Q2q2/1P1Qq3/P1PPPPPP/8");
		assertNotMoveExists("8/8/8/8/2P2q2/3Qq3/PP1PPPPP/8");
		assertMoveExists("8/8/8/8/2Q2q2/2PQq3/PP1PPPPP/8");
		assertNotMoveExists("8/8/8/8/2QP1q2/3Qq3/PPP1PPPP/8");
		assertNotMoveExists("8/8/8/8/2Q2q2/3Pq3/PPP1PPPP/8");
		assertNotMoveExists("8/8/8/8/2Q1Pq2/3Qq3/PPPP1PPP/8");
		assertNotMoveExists("8/8/8/8/2Q2q2/3QP3/PPPP1PPP/8");
		assertNotMoveExists("8/8/8/8/2Q2P2/3Qq3/PPPPP1PP/8");
		assertMoveExists("8/8/8/8/2Q2q2/3QqP2/PPPPP1PP/8");
		assertMoveExists("8/8/8/8/2Q2qP1/3Qq3/PPPPPP1P/8");
		assertMoveExists("8/8/8/8/2Q2q2/3Qq1P1/PPPPPP1P/8");
		assertMoveExists("8/8/8/8/2Q2q1P/3Qq3/PPPPPPP1/8");
		assertMoveExists("8/8/8/8/2Q2q2/3Qq2P/PPPPPPP1/8");
	}


	TEST_F(PawnMoveGeneratorTest, OnePawnForwardBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/pppppppp/8/8/8/8/8 b");
		assertMoveExists("8/8/1ppppppp/p7/8/8/8/8");
		assertMoveExists("8/8/p1pppppp/1p6/8/8/8/8");
		assertMoveExists("8/8/pp1ppppp/2p5/8/8/8/8");
		assertMoveExists("8/8/ppp1pppp/3p4/8/8/8/8");
		assertMoveExists("8/8/pppp1ppp/4p3/8/8/8/8");
		assertMoveExists("8/8/ppppp1pp/5p2/8/8/8/8");
		assertMoveExists("8/8/pppppp1p/6p1/8/8/8/8");
		assertMoveExists("8/8/ppppppp1/7p/8/8/8/8");
		assertMoveCount(8);
	}


	TEST_F(PawnMoveGeneratorTest, TwoPawnsForwardBlack) {
		Fen* fen = new Fen();
		fen->import("8/pppppppp/8/8/8/8/8/8 b");
		assertMoveExists("8/1ppppppp/p7/8/8/8/8/8");
		assertMoveExists("8/p1pppppp/1p6/8/8/8/8/8");
		assertMoveExists("8/pp1ppppp/2p5/8/8/8/8/8");
		assertMoveExists("8/ppp1pppp/3p4/8/8/8/8/8");
		assertMoveExists("8/pppp1ppp/4p3/8/8/8/8/8");
		assertMoveExists("8/ppppp1pp/5p2/8/8/8/8/8");
		assertMoveExists("8/pppppp1p/6p1/8/8/8/8/8");
		assertMoveExists("8/ppppppp1/7p/8/8/8/8/8");

		assertMoveExists("8/1ppppppp/8/p7/8/8/8/8");
		assertMoveExists("8/p1pppppp/8/1p6/8/8/8/8");
		assertMoveExists("8/pp1ppppp/8/2p5/8/8/8/8");
		assertMoveExists("8/ppp1pppp/8/3p4/8/8/8/8");
		assertMoveExists("8/pppp1ppp/8/4p3/8/8/8/8");
		assertMoveExists("8/ppppp1pp/8/5p2/8/8/8/8");
		assertMoveExists("8/pppppp1p/8/6p1/8/8/8/8");
		assertMoveExists("8/ppppppp1/8/7p/8/8/8/8");
		assertMoveCount(16);
	}

	TEST_F(PawnMoveGeneratorTest, BlockersBlack) {
		Fen* fen = new Fen();
		fen->import("8/pppppppp/3qQ3/2q2Q2/8/8/8/8 b");
		assertMoveExists("8/ppppppp1/3qQ3/2q2Q1p/8/8/8/8");
		assertMoveExists("8/ppppppp1/3qQ2p/2q2Q2/8/8/8/8");
		assertMoveExists("8/pppppp1p/3qQ3/2q2Qp1/8/8/8/8");
		assertMoveExists("8/pppppp1p/3qQ1p1/2q2Q2/8/8/8/8");
		assertNotMoveExists("8/ppppp1pp/3qQ3/2q2p2/8/8/8/8");
		assertMoveExists("8/ppppp1pp/3qQp2/2q2Q2/8/8/8/8");
		assertNotMoveExists("8/pppp1ppp/3qQ3/2q1pQ2/8/8/8/8");
		assertNotMoveExists("8/pppp1ppp/3qp3/2q2Q2/8/8/8/8");
		assertNotMoveExists("8/ppp1pppp/3qQ3/2qp1Q2/8/8/8/8");
		assertNotMoveExists("8/ppp1pppp/3pQ3/2q2Q2/8/8/8/8");
		assertNotMoveExists("8/pp1ppppp/3qQ3/2p2Q2/8/8/8/8");
		assertMoveExists("8/pp1ppppp/2pqQ3/2q2Q2/8/8/8/8");
		assertMoveExists("8/p1pppppp/3qQ3/1pq2Q2/8/8/8/8");
		assertMoveExists("8/p1pppppp/1p1qQ3/2q2Q2/8/8/8/8");
		assertMoveExists("8/1ppppppp/3qQ3/p1q2Q2/8/8/8/8");
		assertMoveExists("8/1ppppppp/p2qQ3/2q2Q2/8/8/8/8");
	}