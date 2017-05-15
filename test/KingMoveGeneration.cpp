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