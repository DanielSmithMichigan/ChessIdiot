	#include "Perft.h"

	PerftTest::PerftTest() {
		fen = new Fen();
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	PerftTest::~PerftTest() {
	}

	void PerftTest::SetUp() {
		Board::reset();
	}

	void PerftTest::performPerft(string fenString, uint64_t depth, uint64_t nodes) {
		fen->import(fenString);
		ASSERT_EQ(MoveGenerationController::countMovesAtDepth(depth), nodes);
	}

	TEST_F(PerftTest, InitialPosition) {
		// performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 1, 20);
		// performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2, 400);
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 3, 8902);
		// performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 4, 197281);
		// performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 5, 4865609);
	}