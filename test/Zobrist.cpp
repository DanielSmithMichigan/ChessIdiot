	#include "Zobrist.h"

	ZobristTest::ZobristTest() {
		Init::instance->execute(true);
	}

	ZobristTest::~ZobristTest() {
	}

	unordered_map<string, uint64_t> fenToZobrist;
	unordered_map<uint64_t, string> zobristToFen;

	void ZobristTest::doMove(uint32_t from, uint32_t to) {
		MoveGenerationController::instance->generateAllMoves<false>();
		while (uint32_t currentMove = MoveStack::instance->pop()) {
			if (FROM(currentMove) == from && TO(currentMove) == to) {
				Board::doMove(currentMove);
			}
		}
		while (uint32_t currentMove = MoveStack::instance->pop()) {
		}
	}

	void ZobristTest::checkFenToZobrist() {
		string currentFen = Fen::exportZobristInfo();
		unordered_map<string, uint64_t>::const_iterator tableEntry = fenToZobrist.find(currentFen);
		if (tableEntry != fenToZobrist.end()) {
			ASSERT_EQ(Board::currentState->zobrist, tableEntry->second);
		}
		fenToZobrist[currentFen] = Board::currentState->zobrist;
	}

	void ZobristTest::checkZobristToFen() {
		string currentFen = Fen::exportZobristInfo();
		unordered_map<uint64_t, string>::const_iterator tableEntry = zobristToFen.find(Board::currentState->zobrist);
		if (tableEntry != zobristToFen.end()) {
			ASSERT_EQ(currentFen, tableEntry->second) << "Second: " << tableEntry->second << " Fen: " << currentFen << " First: " << tableEntry->first << " Zobrist: " << Board::currentState->zobrist << endl;
		}
		zobristToFen[Board::currentState->zobrist] = currentFen;
	}

	void ZobristTest::performZobrist(string fenString, uint64_t depth) {
		fenToZobrist.clear();
		Fen::import(fenString);
		MoveGenerationController::instance->runAtDepth(depth, ZobristTest::checkFenToZobrist);
	}

	void ZobristTest::performZobristOpposite(string fenString, uint64_t depth) {
		zobristToFen.clear();
		Fen::import(fenString);
		MoveGenerationController::instance->runAtDepth(depth, ZobristTest::checkZobristToFen);
	}

	TEST_F(ZobristTest, PerftStyleTest) {
		performZobrist("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 3);
		performZobrist("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 3);
		performZobrist("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 3);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 3);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq b3 0 1", 3);
		performZobrist("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 3);
		performZobrist("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 3);
		performZobrist("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2);
		performZobrist("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 2);
		performZobrist("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 2);
		performZobrist("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 2);
		performZobrist("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 2);
		performZobrist("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 2);
	}

	TEST_F(ZobristTest, UniqueZobrist) {
		performZobristOpposite("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 2);
		performZobristOpposite("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 3);
		performZobristOpposite("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 3);
		performZobristOpposite("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 3);
		performZobristOpposite("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq b3 0 1", 3);
		performZobristOpposite("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 3);
		performZobristOpposite("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 3);
		performZobristOpposite("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2);
		performZobristOpposite("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 2);
		performZobristOpposite("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 2);
		performZobristOpposite("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 2);
		performZobristOpposite("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 2);
		performZobristOpposite("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 2);
	}

	TEST_F(ZobristTest, ImportVsDoMove) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -");
		doMove(boardCoordToInt("g1"), boardCoordToInt("h3"));
		uint64_t firstZobrist = Board::currentState->zobrist;
		Fen::import("rnbqkbnr/pppppppp/8/8/8/7N/PPPPPPPP/RNBQKB1R b KQkq -");
		uint64_t secondZobrist = Board::currentState->zobrist;
		ASSERT_EQ(firstZobrist, secondZobrist);
	}

	TEST_F(ZobristTest, MovePawn) {
		Fen::import("r3k2r/Pp1p1ppp/1bp2nbN/nPP5/BB2P3/q4N2/Pp1Pp1PP/R2Q1R1K b kq -");
		Board::remove(BLACK, PAWN, 52);
		uint64_t firstZobrist = Board::currentState->zobrist;
		Fen::import("r3k2r/Pp1p1ppp/1bp2nbN/nPP5/BB2P3/q4N2/Pp1P2PP/R2Q1R1K b kq -");
		uint64_t secondZobrist = Board::currentState->zobrist;
		ASSERT_EQ(firstZobrist, secondZobrist);
	}