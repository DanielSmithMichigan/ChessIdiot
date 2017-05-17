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
		Board::reset();
		fen->import(fenString);
		ASSERT_EQ(MoveGenerationController::countMovesAtDepth(depth), nodes);
	}

	TEST_F(PerftTest, InitialPosition) {
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 1, 20);
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2, 400);
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 3, 8902);
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 4, 197281);
		performPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 5, 4865609);
	}

	TEST_F(PerftTest, Kiwipete) {
		// performPerft("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 1, 48);
		// performPerft("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 2, 2039);
		// performPerft("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 7, 97862);
	}

	TEST_F(PerftTest, Position3) {
		// performPerft("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 1, 14);
		// performPerft("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 2, 191);
	}

	TEST_F(PerftTest, EngineComparison) {
	}