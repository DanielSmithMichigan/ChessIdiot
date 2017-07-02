	#include "Search.h"

	SearchTest::SearchTest() {
		Init::instance->execute(true);
	}

	SearchTest::~SearchTest() {
	}

	TEST_F(SearchTest, WillDetectRepetition) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	}