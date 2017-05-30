	#include "RookMoveGeneration.h"

	RookMoveGenerationTest::RookMoveGenerationTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	RookMoveGenerationTest::~RookMoveGenerationTest() {
	}

	void RookMoveGenerationTest::SetUp() {
		Board::reset();
	}

	TEST_F(RookMoveGenerationTest, OneRookWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4R3/8/8/8 w");
		assertMoveExists("4R3/8/8/8/8/8/8/8");
		assertMoveExists("8/4R3/8/8/8/8/8/8");
		assertMoveExists("8/8/4R3/8/8/8/8/8");
		assertMoveExists("8/8/8/4R3/8/8/8/8");
		assertMoveExists("8/8/8/8/8/4R3/8/8");
		assertMoveExists("8/8/8/8/8/8/4R3/8");
		assertMoveExists("8/8/8/8/8/8/8/4R3");
		assertMoveExists("8/8/8/8/3R4/8/8/8");
		assertMoveExists("8/8/8/8/2R5/8/8/8");
		assertMoveExists("8/8/8/8/6R1/8/8/8");
		assertMoveExists("8/8/8/8/R7/8/8/8");
		assertMoveExists("8/8/8/8/5R2/8/8/8");
		assertMoveExists("8/8/8/8/6R1/8/8/8");
		assertMoveExists("8/8/8/8/7R/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, OneRookWhiteBlocked) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4RP2/8/8/8");
		assertMoveExists("8/8/8/4R3/5P2/8/8/8");
		assertMoveExists("8/8/4R3/8/5P2/8/8/8");
		assertMoveExists("8/4R3/8/8/5P2/8/8/8");
		assertMoveExists("4R3/8/8/8/5P2/8/8/8");
		assertMoveExists("8/8/8/8/5P2/4R3/8/8");
		assertMoveExists("8/8/8/8/5P2/8/4R3/8");
		assertMoveExists("8/8/8/8/5P2/8/8/4R3");
		assertMoveExists("8/8/8/8/3R1P2/8/8/8");
		assertMoveExists("8/8/8/8/2R2P2/8/8/8");
		assertMoveExists("8/8/8/8/1R3P2/8/8/8");
		assertMoveExists("8/8/8/8/R4P2/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, OneRookWhiteAttack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4Rp2/8/8/8");
		assertMoveExists("8/8/8/8/5R2/8/8/8");
		assertMoveExists("8/8/8/4R3/5p2/8/8/8");
		assertMoveExists("8/8/4R3/8/5p2/8/8/8");
		assertMoveExists("8/4R3/8/8/5p2/8/8/8");
		assertMoveExists("4R3/8/8/8/5p2/8/8/8");
		assertMoveExists("8/8/8/8/5p2/4R3/8/8");
		assertMoveExists("8/8/8/8/5p2/8/4R3/8");
		assertMoveExists("8/8/8/8/5p2/8/8/4R3");
		assertMoveExists("8/8/8/8/3R1p2/8/8/8");
		assertMoveExists("8/8/8/8/2R2p2/8/8/8");
		assertMoveExists("8/8/8/8/1R3p2/8/8/8");
		assertMoveExists("8/8/8/8/R4p2/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, OneRookBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4r3/8/8/8 b");
		assertMoveExists("4r3/8/8/8/8/8/8/8");
		assertMoveExists("8/4r3/8/8/8/8/8/8");
		assertMoveExists("8/8/4r3/8/8/8/8/8");
		assertMoveExists("8/8/8/4r3/8/8/8/8");
		assertMoveExists("8/8/8/8/8/4r3/8/8");
		assertMoveExists("8/8/8/8/8/8/4r3/8");
		assertMoveExists("8/8/8/8/8/8/8/4r3");
		assertMoveExists("8/8/8/8/3r4/8/8/8");
		assertMoveExists("8/8/8/8/2r5/8/8/8");
		assertMoveExists("8/8/8/8/6r1/8/8/8");
		assertMoveExists("8/8/8/8/r7/8/8/8");
		assertMoveExists("8/8/8/8/5r2/8/8/8");
		assertMoveExists("8/8/8/8/6r1/8/8/8");
		assertMoveExists("8/8/8/8/7r/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, OneRookBlackBlocked) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4rp2/8/8/8 b");
		assertMoveExists("8/8/8/4r3/5p2/8/8/8");
		assertMoveExists("8/8/4r3/8/5p2/8/8/8");
		assertMoveExists("8/4r3/8/8/5p2/8/8/8");
		assertMoveExists("4r3/8/8/8/5p2/8/8/8");
		assertMoveExists("8/8/8/8/5p2/4r3/8/8");
		assertMoveExists("8/8/8/8/5p2/8/4r3/8");
		assertMoveExists("8/8/8/8/5p2/8/8/4r3");
		assertMoveExists("8/8/8/8/3r1p2/8/8/8");
		assertMoveExists("8/8/8/8/2r2p2/8/8/8");
		assertMoveExists("8/8/8/8/1r3p2/8/8/8");
		assertMoveExists("8/8/8/8/r4p2/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, OneRookBlackAttack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4rP2/8/8/8 b");
		assertMoveExists("8/8/8/8/5r2/8/8/8");
		assertMoveExists("8/8/8/4r3/5P2/8/8/8");
		assertMoveExists("8/8/4r3/8/5P2/8/8/8");
		assertMoveExists("8/4r3/8/8/5P2/8/8/8");
		assertMoveExists("4r3/8/8/8/5P2/8/8/8");
		assertMoveExists("8/8/8/8/5P2/4r3/8/8");
		assertMoveExists("8/8/8/8/5P2/8/4r3/8");
		assertMoveExists("8/8/8/8/5P2/8/8/4r3");
		assertMoveExists("8/8/8/8/3r1P2/8/8/8");
		assertMoveExists("8/8/8/8/2r2P2/8/8/8");
		assertMoveExists("8/8/8/8/1r3P2/8/8/8");
		assertMoveExists("8/8/8/8/r4P2/8/8/8");
	}

	TEST_F(RookMoveGenerationTest, Quiescence) {
		Fen* fen = new Fen();
		fen->import("8/2p1R1p1/8/8/8/8/8/8 w");
		assertMoveExists("8/2p3R1/8/8/8/8/8/8", "quiescence");
		assertMoveExists("8/2R3p1/8/8/8/8/8/8", "quiescence");
		assertNotMoveExists("8/2pR2p1/8/8/8/8/8/8", "quiescence");
	}