	#include "KingMoveGeneration.h"

	KingMoveGenerationTest::KingMoveGenerationTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	KingMoveGenerationTest::~KingMoveGenerationTest() {
	}

	void KingMoveGenerationTest::SetUp() {
		Board::reset();
	}

	TEST_F(KingMoveGenerationTest, KingWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4P3/4K3/4p3/8/8 w");
		assertMoveExists("8/8/8/4PK2/8/4p3/8/8");
		assertMoveExists("8/8/8/4P3/5K2/4p3/8/8");
		assertMoveExists("8/8/8/4P3/8/4pK2/8/8");
		assertMoveExists("8/8/8/4P3/8/3Kp3/8/8");
		assertMoveExists("8/8/8/4P3/3K4/4p3/8/8");
		assertMoveExists("8/8/8/3KP3/8/4p3/8/8");
		assertNotMoveExists("8/8/8/4K3/8/4p3/8/8");
		assertMoveExists("8/8/8/4P3/8/4K3/8/8");
	}

	TEST_F(KingMoveGenerationTest, KingBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4P3/4k3/4p3/8/8 b");
		assertMoveExists("8/8/8/3kP3/8/4p3/8/8");
		assertMoveExists("8/8/8/4P3/3k4/4p3/8/8");
		assertMoveExists("8/8/8/4P3/8/3kp3/8/8");
		assertMoveExists("8/8/8/4P3/8/4pk2/8/8");
		assertMoveExists("8/8/8/4P3/5k2/4p3/8/8");
		assertMoveExists("8/8/8/4Pk2/8/4p3/8/8");
		assertMoveExists("8/8/8/4k3/8/4p3/8/8");
		assertNotMoveExists("8/8/8/4P3/8/4k3/8/8");
	}

	TEST_F(KingMoveGenerationTest, WhiteCastlingRight) {
		Fen* fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/R3K2R w Kk");
		assertMoveExists("r3k2r/8/8/8/8/8/8/R4RK1");
	}

	TEST_F(KingMoveGenerationTest, WhiteCastlingLeft) {
		Fen* fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/R3K2R w Qq");
		assertMoveExists("r3k2r/8/8/8/8/8/8/2KR3R");
	}

	TEST_F(KingMoveGenerationTest, BlackCastlingRight) {
		Fen* fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/R3K2R b Kk");
		assertMoveExists("r4rk1/8/8/8/8/8/8/R3K2R");
	}

	TEST_F(KingMoveGenerationTest, BlackCastlingLeft) {
		Fen* fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/R3K2R b Qq");
		assertMoveExists("2kr3r/8/8/8/8/8/8/R3K2R");
	}

	TEST_F(KingMoveGenerationTest, BugOne) {
		Fen * fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1");
		assertMoveExists("r6r/4k3/8/8/8/8/8/R3K1R1");
	}

	TEST_F(KingMoveGenerationTest, BugTwo) {
		Fen *fen = new Fen();
		fen->import("r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1");
		assertMoveExists("2kr3r/8/8/8/8/8/8/1R2K2R");
	}

	TEST_F(KingMoveGenerationTest, BugThree) {
		Fen::import("rnbqkB1r/pppp1ppp/4pn2/8/8/1P6/P1PPPPPP/RN1QKBNR b KQkq -");
		assertNotMoveExists("rnbq1rk1/pppp1ppp/4pn2/8/8/1P6/P1PPPPPP/RN1QKBNR");
	}

	TEST_F(KingMoveGenerationTest, Quiescence) {
		Fen::import("8/8/4n1n1/5K2/8/8/8/8 w");
		assertNotMoveExists("8/8/4nKn1/8/8/8/8/8", "quiescence");
		assertNotMoveExists("8/8/4n1n1/6K1/8/8/8/8", "quiescence");
		assertNotMoveExists("8/8/4n1n1/8/6K1/8/8/8", "quiescence");
		assertNotMoveExists("8/8/4n1n1/8/5K2/8/8/8", "quiescence");
		assertNotMoveExists("8/8/4n1n1/8/4K3/8/8/8", "quiescence");
		assertNotMoveExists("8/8/4n1n1/4K3/8/8/8/8", "quiescence");
		assertMoveExists("8/8/4K1n1/8/8/8/8/8", "quiescence");
		assertMoveExists("8/8/4n1K1/8/8/8/8/8", "quiescence");
	}