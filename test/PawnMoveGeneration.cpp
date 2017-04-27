	#include "PawnMoveGeneration.h"

	PawnMoveGeneratorTest::PawnMoveGeneratorTest() {
	}

	PawnMoveGeneratorTest::~PawnMoveGeneratorTest() {
	}

	void PawnMoveGeneratorTest::SetUp() {
		Board::reset();
	}

	TEST_F(PawnMoveGeneratorTest, OnePawnForward) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/8/PPPPPPPP/8 w KQkq -");
		assertMoveExists("8/8/8/8/8/P7/1PPPPPPP/8");
		assertMoveExists("8/8/8/8/8/1P6/P1PPPPPP/8");
		assertMoveExists("8/8/8/8/8/2P5/PP1PPPPP/8");
		assertMoveExists("8/8/8/8/8/3P4/PPP1PPPP/8");
		assertMoveExists("8/8/8/8/8/4P3/PPPP1PPP/8");
		assertMoveExists("8/8/8/8/8/5P2/PPPPP1PP/8");
		assertMoveExists("8/8/8/8/8/6P1/PPPPPP1P/8");
		assertMoveExists("8/8/8/8/8/7P/PPPPPPP1/8");
	}