	#include "KnightMoveGeneration.h"

	KnightMoveGenerationTest::KnightMoveGenerationTest() {
		Init::instance->execute(true);
	}

	KnightMoveGenerationTest::~KnightMoveGenerationTest() {
	}

	TEST_F(KnightMoveGenerationTest, OneKnightWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4N3/8/8/8 w");
		assertMoveExists("8/8/8/8/8/8/5N2/8");
		assertMoveExists("8/8/8/8/8/6N1/8/8");
		assertMoveExists("8/8/8/6N1/8/8/8/8");
		assertMoveExists("8/8/5N2/8/8/8/8/8");
		assertMoveExists("8/8/3N4/8/8/8/8/8");
		assertMoveExists("8/8/8/2N5/8/8/8/8");
		assertMoveExists("8/8/8/8/8/2N5/8/8");
		assertMoveExists("8/8/8/8/8/8/3N4/8");
		assertMoveCount(8);
	}

	TEST_F(KnightMoveGenerationTest, OneKnightWhiteAttack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4N3/6p1/5R2/8 w");
		assertMoveExists("8/8/8/8/8/6N1/5R2/8");
		assertNotMoveExists("8/8/8/8/8/6p1/5N2/8");
	}

	TEST_F(KnightMoveGenerationTest, OneKnightBlackAttack) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/4n3/6p1/5R2/8 b");
		assertMoveExists("8/8/8/8/8/6p1/5n2/8");
		assertNotMoveExists("8/8/8/8/8/6n1/5R2/8");
	}

	TEST_F(KnightMoveGenerationTest, Quiescence) {
		Fen* fen = new Fen();
		fen->import("8/3p1p2/8/4N3/8/8/8/8 w");
		assertNotMoveExists("8/3p1p2/6N1/8/8/8/8/8", "quiescence");
		assertNotMoveExists("8/3p1p2/8/8/6N1/8/8/8", "quiescence");
		assertNotMoveExists("8/3p1p2/8/8/8/5N2/8/8", "quiescence");
		assertNotMoveExists("8/3p1p2/8/8/8/3N4/8/8", "quiescence");
		assertNotMoveExists("8/3p1p2/8/8/2N5/8/8/8", "quiescence");
		assertNotMoveExists("8/3p1p2/2N5/8/8/8/8/8", "quiescence");
		assertMoveExists("8/3N1p2/8/8/8/8/8/8", "quiescence");
		assertMoveExists("8/3p1N2/8/8/8/8/8/8", "quiescence");
	}