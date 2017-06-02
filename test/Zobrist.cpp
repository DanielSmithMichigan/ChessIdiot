	#include "Zobrist.h"

	ZobristTest::ZobristTest() {
		fen = new Fen();
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	ZobristTest::~ZobristTest() {
	}

	unordered_map<string, uint64_t> fenToZobrist;

	void ZobristTest::checkMap() {
		string currentFen = Fen::exportZobristInfo();
		unordered_map<string, uint64_t>::const_iterator tableEntry = fenToZobrist.find(currentFen);
		if (tableEntry != fenToZobrist.end()) {
			ASSERT_EQ(Board::currentState->zobrist, tableEntry->second);
		}
		fenToZobrist[currentFen] = Board::currentState->zobrist;
	}

	void ZobristTest::performZobrist(string fenString, uint64_t depth) {
		Board::reset();
		MoveStack::instance->reset();
		fen->import(fenString);
		fenToZobrist.clear();
		MoveGenerationController::instance->runAtDepth(depth, ZobristTest::checkMap);
	}

	TEST_F(ZobristTest, PerftStyleTest) {
		performZobrist("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 3);
		performZobrist("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 3);
		performZobrist("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 3);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 3);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq e3 0 1", 3);
		performZobrist("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 3);
		performZobrist("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 3);
		performZobrist("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2);
		performZobrist("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 2);
		performZobrist("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 2);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 2);
		performZobrist("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 2);
		performZobrist("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 2);
	}