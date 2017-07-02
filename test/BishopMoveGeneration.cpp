	#include "BishopMoveGeneration.h"

	BishopMoveGenerationTest::BishopMoveGenerationTest() {
		Init::instance->execute(true);
	}

	BishopMoveGenerationTest::~BishopMoveGenerationTest() {
	}

	void BishopMoveGenerationTest::SetUp() {
		Board::reset();
	}

	TEST_F(BishopMoveGenerationTest, OneBishopBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4b3/8/8/8/8 b");
		// Down Right
		assertMoveExists("8/8/8/8/5b2/8/8/8");
		assertMoveExists("8/8/8/8/8/6b1/8/8");
		assertMoveExists("8/8/8/8/8/8/7b/8");

		// Up Right
		assertMoveExists("8/8/5b2/8/8/8/8/8");
		assertMoveExists("8/6b1/8/8/8/8/8/8");
		assertMoveExists("7b/8/8/8/8/8/8/8");

		// Up Left
		assertMoveExists("8/8/3b4/8/8/8/8/8");
		assertMoveExists("8/2b5/8/8/8/8/8/8");
		assertMoveExists("1b6/8/8/8/8/8/8/8");

		// Down Left
		assertMoveExists("8/8/8/8/3b4/8/8/8");
		assertMoveExists("8/8/8/8/8/2b5/8/8");
		assertMoveExists("8/8/8/8/8/8/1b6/8");
		assertMoveExists("8/8/8/8/8/8/8/b7");
	}

	TEST_F(BishopMoveGenerationTest, OneBlockedBishopBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4p3/5b2/8/8/8 b");
		assertMoveExists("8/8/8/4p1b1/8/8/8/8");
		assertMoveExists("8/8/7b/4p3/8/8/8/8");
		assertMoveExists("8/8/8/4p3/8/4b3/8/8");
		assertMoveExists("8/8/8/4p3/8/8/3b4/8");
		assertMoveExists("8/8/8/4p3/8/8/8/2b5");
		assertMoveExists("8/8/8/4p3/8/6b1/8/8");
		assertMoveExists("8/8/8/4p3/8/8/7b/8");
		assertNotMoveExists("8/8/8/4b3/8/8/8/8");
	}

	TEST_F(BishopMoveGenerationTest, AttackingBishopBlack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4P3/5b2/8/8/8 b");
		assertMoveExists("8/8/8/4P1b1/8/8/8/8");
		assertMoveExists("8/8/7b/4P3/8/8/8/8");
		assertMoveExists("8/8/8/4P3/8/4b3/8/8");
		assertMoveExists("8/8/8/4P3/8/8/3b4/8");
		assertMoveExists("8/8/8/4P3/8/8/8/2b5");
		assertMoveExists("8/8/8/4P3/8/6b1/8/8");
		assertMoveExists("8/8/8/4P3/8/8/7b/8");
		assertMoveExists("8/8/8/4b3/8/8/8/8");
	}

	TEST_F(BishopMoveGenerationTest, OneBishopWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4B3/8/8/8/8 w");
		// Down Right
		assertMoveExists("8/8/8/8/5B2/8/8/8");
		assertMoveExists("8/8/8/8/8/6B1/8/8");
		assertMoveExists("8/8/8/8/8/8/7B/8");

		// Up Right
		assertMoveExists("8/8/5B2/8/8/8/8/8");
		assertMoveExists("8/6B1/8/8/8/8/8/8");
		assertMoveExists("7B/8/8/8/8/8/8/8");

		// Up Left
		assertMoveExists("8/8/3B4/8/8/8/8/8");
		assertMoveExists("8/2B5/8/8/8/8/8/8");
		assertMoveExists("1B6/8/8/8/8/8/8/8");

		// Down Left
		assertMoveExists("8/8/8/8/3B4/8/8/8");
		assertMoveExists("8/8/8/8/8/2B5/8/8");
		assertMoveExists("8/8/8/8/8/8/1B6/8");
		assertMoveExists("8/8/8/8/8/8/8/B7");
	}

	TEST_F(BishopMoveGenerationTest, OneBlockedBishopWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4P3/5B2/8/8/8 w");
		assertMoveExists("8/8/8/4P1B1/8/8/8/8");
		assertMoveExists("8/8/7B/4P3/8/8/8/8");
		assertMoveExists("8/8/8/4P3/8/4B3/8/8");
		assertMoveExists("8/8/8/4P3/8/8/3B4/8");
		assertMoveExists("8/8/8/4P3/8/8/8/2B5");
		assertMoveExists("8/8/8/4P3/8/6B1/8/8");
		assertMoveExists("8/8/8/4P3/8/8/7B/8");
		assertNotMoveExists("8/8/8/4B3/8/8/8/8");
	}

	TEST_F(BishopMoveGenerationTest, AttackingBishopWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4p3/5B2/8/8/8 w");
		assertMoveExists("8/8/8/4p1B1/8/8/8/8");
		assertMoveExists("8/8/7B/4p3/8/8/8/8");
		assertMoveExists("8/8/8/4p3/8/4B3/8/8");
		assertMoveExists("8/8/8/4p3/8/8/3B4/8");
		assertMoveExists("8/8/8/4p3/8/8/8/2B5");
		assertMoveExists("8/8/8/4p3/8/6B1/8/8");
		assertMoveExists("8/8/8/4p3/8/8/7B/8");
		assertMoveExists("8/8/8/4B3/8/8/8/8");
	}

	TEST_F(BishopMoveGenerationTest, Quiescence) {
		Fen* fen = new Fen();
		fen->import("8/8/8/4p3/5B2/8/8/8 w");
		assertNotMoveExists("8/8/8/4p1B1/8/8/8/8", "quiescence");
		assertNotMoveExists("8/8/7B/4p3/8/8/8/8", "quiescence");
		assertNotMoveExists("8/8/8/4p3/8/4B3/8/8", "quiescence");
		assertNotMoveExists("8/8/8/4p3/8/8/3B4/8", "quiescence");
		assertNotMoveExists("8/8/8/4p3/8/8/8/2B5", "quiescence");
		assertNotMoveExists("8/8/8/4p3/8/6B1/8/8", "quiescence");
		assertNotMoveExists("8/8/8/4p3/8/8/7B/8", "quiescence");
		assertMoveExists("8/8/8/4B3/8/8/8/8", "quiescence");
	}