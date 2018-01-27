	#include "QueenMoveGeneration.h"

	QueenMoveGenerationTest::QueenMoveGenerationTest() {
		Init::instance->execute(true);
	}

	QueenMoveGenerationTest::~QueenMoveGenerationTest() {
	}

	void QueenMoveGenerationTest::SetUp() {
		Board::reset();
	}

	TEST_F(QueenMoveGenerationTest, OneQueenWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/8/6p1/5Qp1/4PPP1/8/8 w");
		assertMoveExists("8/8/8/6Q1/6p1/4PPP1/8/8");
		assertMoveExists("8/8/8/6p1/6Q1/4PPP1/8/8");
		assertMoveExists("8/8/8/5Qp1/6p1/4PPP1/8/8");
		assertMoveExists("8/8/5Q2/6p1/6p1/4PPP1/8/8");
		assertMoveExists("8/5Q2/8/6p1/6p1/4PPP1/8/8");
		assertMoveExists("5Q2/8/8/6p1/6p1/4PPP1/8/8");
		assertMoveExists("8/8/8/4Q1p1/6p1/4PPP1/8/8");
		assertMoveExists("8/8/3Q4/6p1/6p1/4PPP1/8/8");
		assertMoveExists("8/2Q5/8/6p1/6p1/4PPP1/8/8");
		assertMoveExists("1Q6/8/8/6p1/6p1/4PPP1/8/8");
		assertMoveExists("8/8/8/6p1/4Q1p1/4PPP1/8/8");
		assertMoveExists("8/8/8/6p1/3Q2p1/4PPP1/8/8");
		assertMoveExists("8/8/8/6p1/2Q3p1/4PPP1/8/8");
		assertMoveExists("8/8/8/6p1/Q5p1/4PPP1/8/8");
		assertNotMoveExists("8/8/8/6p1/6p1/4PPQ1/8/8");
		assertNotMoveExists("8/8/8/6p1/6p1/4PQP1/8/8");
		assertNotMoveExists("8/8/8/6p1/6p1/4QPP1/8/8");
		assertNotMoveExists("8/8/8/6p1/6p1/4PPP1/5Q2/8");
	}

	TEST_F(QueenMoveGenerationTest, Quiescence) {
		Fen* fen = new Fen();
		fen->import("8/2p3p1/8/4Q3/8/8/8/8 w");
		assertMoveExists("8/2Q3p1/8/8/8/8/8/8", "quiescence");
		assertMoveExists("8/2p3Q1/8/8/8/8/8/8", "quiescence");
		assertNotMoveExists("8/2p3p1/4Q3/8/8/8/8/8", "quiescence");
	}