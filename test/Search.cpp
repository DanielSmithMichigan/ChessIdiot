	#include "Search.h"

	SearchTest::SearchTest() {
		Init::instance->execute(true);
	}

	SearchTest::~SearchTest() {
	}

	TEST_F(SearchTest, WillDetectRepetition) {
		Uci::instance->position("fen 8/3k4/7p/8/8/8/3K2R1/8 w - - 0 1 moves g2h2 d7d8 h2g2 d8d7");
		uint32_t bestMove = Search::instance->iterativeDeepening(3);
		string bestMoveString = intToBoardCoord(FROM(bestMove)) + intToBoardCoord(TO(bestMove));
		ASSERT_NE(bestMoveString, "g2h2");
	}

	TEST_F(SearchTest, WillDetectRepetitionNegative) {
		Uci::instance->position("fen 8/3k4/7p/8/8/8/3K2R1/8 w - - 0 1 moves g2f2 d7d8 f2g2 d8d7");
		uint32_t bestMove = Search::instance->iterativeDeepening(3);
		string bestMoveString = intToBoardCoord(FROM(bestMove)) + intToBoardCoord(TO(bestMove));
		ASSERT_EQ(bestMoveString, "g2h2");
	}

	TEST_F(SearchTest, CanSearchGt50) {
		Uci::instance->position("fen 8/3k4/7p/8/8/8/3K2R1/8 w - - 100 100 moves g2f2 d7d8 f2g2 d8d7");
		Search::instance->timeRemaining(300000);
		uint32_t bestMove = Search::instance->iterativeDeepening();
		cout << "BEST: " << bestMove << endl;
	}