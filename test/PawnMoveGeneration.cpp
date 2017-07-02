	#include "PawnMoveGeneration.h"

	PawnMoveGeneratorTest::PawnMoveGeneratorTest() {
		Init::instance->execute(true);
	}

	PawnMoveGeneratorTest::~PawnMoveGeneratorTest() {
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
	}

	TEST_F(PawnMoveGeneratorTest, EnPassantWhiteRight) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4pPp1/8/8/8/8 w - g6");
		assertMoveExists("8/8/6P1/4p3/8/8/8/8");
		assertNotMoveExists("8/8/4P3/6p1/8/8/8/8");
	}

	TEST_F(PawnMoveGeneratorTest, EnPassantWhiteLeft) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4pPp1/8/8/8/8 w - e6");
		assertMoveExists("8/8/4P3/6p1/8/8/8/8");
		assertNotMoveExists("8/8/6P1/4p3/8/8/8/8");
	}

	TEST_F(PawnMoveGeneratorTest, AttackWhiteLeft) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/7r/r7/PP6/8 w");
		assertMoveExists("8/8/8/8/7r/P7/P7/8");
		assertNotMoveExists("8/8/8/8/7P/r7/1P6/8");
	}

	TEST_F(PawnMoveGeneratorTest, AttackWhiteRight) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/r7/7r/6PP/8 w");
		assertMoveExists("8/8/8/8/r7/7P/7P/8");
		assertNotMoveExists("8/8/8/8/P7/7r/6P1/8");
	}

	TEST_F(PawnMoveGeneratorTest, TwoPawnsForwardWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/8/PPPPPPPP/8 w");
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


	TEST_F(PawnMoveGeneratorTest, WhitePromotion) {
		Fen* fen = new Fen();
		fen->import("8/7P/8/8/8/8/8/8 w");
		assertMoveExists("7Q/8/8/8/8/8/8/8");
		assertMoveExists("7R/8/8/8/8/8/8/8");
		assertMoveExists("7B/8/8/8/8/8/8/8");
		assertMoveExists("7N/8/8/8/8/8/8/8");
	}


	TEST_F(PawnMoveGeneratorTest, WhitePromotionAttack) {
		Fen* fen = new Fen();
		fen->import("3n1n2/4P3/8/8/8/8/8/8 w");
		assertMoveExists("3n1N2/8/8/8/8/8/8/8");
		assertMoveExists("3n1R2/8/8/8/8/8/8/8");
		assertMoveExists("3n1Q2/8/8/8/8/8/8/8");
		assertMoveExists("3n1B2/8/8/8/8/8/8/8");
		assertMoveExists("3N1n2/8/8/8/8/8/8/8");
		assertMoveExists("3R1n2/8/8/8/8/8/8/8");
		assertMoveExists("3Q1n2/8/8/8/8/8/8/8");
		assertMoveExists("3B1n2/8/8/8/8/8/8/8");
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
	}

	TEST_F(PawnMoveGeneratorTest, AttackBlackLeft) {
		Fen* fen = new Fen();
		fen->import("8/pp6/R7/7R/8/8/8/8 b");
		assertMoveExists("8/p7/p7/7R/8/8/8/8");
		assertNotMoveExists("8/1p6/R7/7p/8/8/8/8");
	}

	TEST_F(PawnMoveGeneratorTest, AttackBlackRight) {
		Fen* fen = new Fen();
		fen->import("8/6pp/7R/R7/8/8/8/8 b");
		assertMoveExists("8/7p/7p/R7/8/8/8/8");
		assertNotMoveExists("8/6p1/7R/p7/8/8/8/8");
	}

	TEST_F(PawnMoveGeneratorTest, EnPassantBlackLeft) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/1PpP4/8/8/8 b - b3");
		assertMoveExists("8/8/8/8/3P4/1p6/8/8");
		assertNotMoveExists("8/8/8/8/1P6/3p4/8/8");
	}

	TEST_F(PawnMoveGeneratorTest, EnPassantBlackRight) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/1PpP4/8/8/8 b - b3");
		assertMoveExists("8/8/8/8/3P4/1p6/8/8");
		assertNotMoveExists("8/8/8/8/1P6/3p4/8/8");
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

	TEST_F(PawnMoveGeneratorTest, CapturePromotion) {
		Fen *fen = new Fen();
		fen->import("n1n5/1Pk5/8/8/8/8/5Kp1/5N1N b");
		assertMoveExists("n1n5/1Pk5/8/8/8/8/5K2/5N1r");
	}