	#include "BishopMoveGeneration.h"

	BishopMoveGenerationTest::BishopMoveGenerationTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	BishopMoveGenerationTest::~BishopMoveGenerationTest() {
	}

	void BishopMoveGenerationTest::SetUp() {
		Board::reset();
	}

	TEST_F(BishopMoveGenerationTest, OneBishopWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4B3/8/8/8/8 w");
		assertMoveExists("1B6/8/8/8/8/8/8/8");
		assertMoveExists("7B/8/8/8/8/8/8/8");
		assertMoveExists("8/2B5/8/8/8/8/8/8");
		assertMoveExists("8/6B1/8/8/8/8/8/8");
		assertMoveExists("8/8/3B4/8/8/8/8/8");
		assertMoveExists("8/8/5B2/8/8/8/8/8");
		assertMoveExists("8/8/8/8/3B4/8/8/8");
		assertMoveExists("8/8/8/8/5B2/8/8/8");
		assertMoveExists("8/8/8/8/8/2B5/8/8");
		assertMoveExists("8/8/8/8/8/6B1/8/8");
		assertMoveExists("8/8/8/8/8/8/1B6/8");
		assertMoveExists("8/8/8/8/8/8/7B/8");
		assertMoveExists("8/8/8/8/8/8/8/B7");
	}

	TEST_F(BishopMoveGenerationTest, OneBlockedBishop) {
		Fen* fen = new Fen();
		fen->import("8/8/3R4/4B3/8/8/8/8 w");
		assertMoveExists("1B6/8/8/8/8/8/8/8");
	}