	#include "Uci.h"

	UciTest::UciTest() {
		Init::instance->execute();
	}

	UciTest::~UciTest() {
	}

	TEST_F(UciTest, InitialPosition) {
		Uci::instance->position("startpos");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -");
	}

	TEST_F(UciTest, Position) {
		Uci::instance->position("fen rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 1");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq -");
	}

	TEST_F(UciTest, PawnDoubleWhite) {
		Uci::instance->position("fen rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 1 moves f2f4");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/pppppppp/8/8/4PP2/8/PPPP2PP/RNBQKBNR b KQkq f3");
	}

	TEST_F(UciTest, PawnDoubleBlack) {
		Uci::instance->position("fen rnbqkbnr/pppppppp/8/8/4PP2/8/PPPP2PP/RNBQKBNR b KQkq - 0 1 moves f7f5");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/ppppp1pp/8/5p2/4PP2/8/PPPP2PP/RNBQKBNR w KQkq f6");
	}

	TEST_F(UciTest, TwoMoves) {
		Uci::instance->position("fen rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 0 1 moves f2f4 f7f5");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/ppppp1pp/8/5p2/4PP2/8/PPPP2PP/RNBQKBNR w KQkq f6");
	}

	TEST_F(UciTest, EnPassantWhite) {
		Uci::instance->position("fen rnbqkbnr/ppp1p1pp/8/3pPp2/5P2/8/PPPP2PP/RNBQKBNR w KQkq d6 0 3 moves e5d6");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/ppp1p1pp/3P4/5p2/5P2/8/PPPP2PP/RNBQKBNR b KQkq -");
	}

	TEST_F(UciTest, EnPassantBlack) {
		Uci::instance->position("fen rnbqkbnr/pp2p1pp/3P4/5p2/2pP1P2/6P1/PPP4P/RNBQKBNR b KQkq d3 0 5 moves c4d3");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkbnr/pp2p1pp/3P4/5p2/5P2/3p2P1/PPP4P/RNBQKBNR w KQkq -");
	}

	TEST_F(UciTest, CastleWhiteRight) {
		Uci::instance->position("fen rnbqkb1r/pp4pp/3Ppn2/5p2/5P2/3p1NP1/PPP1B2P/RNBQK2R w KQkq - 0 8 moves e1g1");
		ASSERT_EQ(Fen::exportLegacyBoard(), "rnbqkb1r/pp4pp/3Ppn2/5p2/5P2/3p1NP1/PPP1B2P/RNBQ1RK1 b kq -");
	}

	TEST_F(UciTest, CastleWhiteLeft) {
		Uci::instance->position("fen r3k2r/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/R3K2R w KQkq - 3 13 moves e1c1");
		ASSERT_EQ(Fen::exportLegacyBoard(), "r3k2r/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/2KR3R b kq -");
	}

	TEST_F(UciTest, CastleBlackRight) {
		Uci::instance->position("fen r3k2r/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/2KR3R b kq - 4 13 moves e8g8");
		ASSERT_EQ(Fen::exportLegacyBoard(), "r4rk1/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - -");
	}

	TEST_F(UciTest, CastleBlackLeft) {
		Uci::instance->position("fen r3k2r/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/2KR3R b kq - 4 13 moves e8c8");
		ASSERT_EQ(Fen::exportLegacyBoard(), "2kr3r/ppqb2bp/2nPpnp1/5p2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - -");
	}

	TEST_F(UciTest, PromoteQueenWhite) {
		Uci::instance->position("fen 2kr3r/ppPb2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - - 1 15 moves c7d8q");
		ASSERT_EQ(Fen::exportLegacyBoard(), "2kQ3r/pp1b2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R b - -");
	}

	TEST_F(UciTest, PromoteRookWhite) {
		Uci::instance->position("fen 2kr3r/ppPb2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - - 1 15 moves c7d8r");
		ASSERT_EQ(Fen::exportLegacyBoard(), "2kR3r/pp1b2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R b - -");
	}

	TEST_F(UciTest, PromoteBishopWhite) {
		Uci::instance->position("fen 2kr3r/ppPb2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - - 1 15 moves c7d8b");
		ASSERT_EQ(Fen::exportLegacyBoard(), "2kB3r/pp1b2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R b - -");
	}

	TEST_F(UciTest, PromoteKnightWhite) {
		Uci::instance->position("fen 2kr3r/ppPb2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R w - - 1 15 moves c7d8n");
		ASSERT_EQ(Fen::exportLegacyBoard(), "2kN3r/pp1b2bp/4pnp1/4np2/5P2/NPPp1NP1/P1QBB2P/2KR3R b - -");
	}

	TEST_F(UciTest, PromoteQueenBlack) {
		Uci::instance->position("fen 7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB2pP/2KR3R b - - 1 21 moves g2g1q");
		ASSERT_EQ(Fen::exportLegacyBoard(), "7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB3P/2KR2qR w - -");
	}

	TEST_F(UciTest, PromoteRookBlack) {
		Uci::instance->position("fen 7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB2pP/2KR3R b - - 1 21 moves g2g1r");
		ASSERT_EQ(Fen::exportLegacyBoard(), "7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB3P/2KR2rR w - -");
	}

	TEST_F(UciTest, PromoteBishopBlack) {
		Uci::instance->position("fen 7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB2pP/2KR3R b - - 1 21 moves g2g1b");
		ASSERT_EQ(Fen::exportLegacyBoard(), "7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB3P/2KR2bR w - -");
	}

	TEST_F(UciTest, PromoteKnightBlack) {
		Uci::instance->position("fen 7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB2pP/2KR3R b - - 1 21 moves g2g1n");
		ASSERT_EQ(Fen::exportLegacyBoard(), "7r/pp1bk1bp/3Npn2/5p2/4B3/NPPp4/P1QB3P/2KR2nR w - -");
	}