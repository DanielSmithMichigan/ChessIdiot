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

	TEST_F(UciTest, StrangeBug) {
		Uci::instance->readLine("position startpos");
		Uci::instance->readLine("go wtime 290003 btime 300000 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5");
		Uci::instance->readLine("go wtime 290003 btime 290054 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3");
		Uci::instance->readLine("go wtime 280341 btime 290054 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6");
		Uci::instance->readLine("go wtime 280341 btime 280440 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5");
		Uci::instance->readLine("go wtime 270999 btime 280440 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6");
		Uci::instance->readLine("go wtime 270999 btime 271144 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3");
		Uci::instance->readLine("go wtime 261970 btime 271144 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4");
		Uci::instance->readLine("go wtime 261970 btime 262159 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3");
		Uci::instance->readLine("go wtime 253238 btime 262159 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6");
		Uci::instance->readLine("go wtime 253238 btime 253474 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4");
		Uci::instance->readLine("go wtime 244801 btime 253474 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5");
		Uci::instance->readLine("go wtime 244801 btime 245076 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3");
		Uci::instance->readLine("go wtime 236646 btime 245076 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4");
		Uci::instance->readLine("go wtime 236646 btime 236961 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2");
		Uci::instance->readLine("go wtime 228760 btime 236961 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6");
		Uci::instance->readLine("go wtime 228760 btime 229116 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5");
		Uci::instance->readLine("go wtime 221138 btime 229116 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5");
		Uci::instance->readLine("go wtime 221138 btime 221532 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5");
		Uci::instance->readLine("go wtime 213771 btime 221532 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2");
		Uci::instance->readLine("go wtime 213771 btime 214200 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2");
		Uci::instance->readLine("go wtime 206650 btime 214200 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5");
		Uci::instance->readLine("go wtime 206650 btime 207114 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4");
		Uci::instance->readLine("go wtime 199766 btime 207114 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3");
		Uci::instance->readLine("go wtime 199766 btime 200263 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3");
		Uci::instance->readLine("go wtime 193111 btime 200263 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8");
		Uci::instance->readLine("go wtime 193111 btime 193640 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3");
		Uci::instance->readLine("go wtime 186678 btime 193640 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6");
		Uci::instance->readLine("go wtime 186678 btime 187240 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1");
		Uci::instance->readLine("go wtime 180459 btime 187240 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5");
		Uci::instance->readLine("go wtime 180459 btime 181053 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3");
		Uci::instance->readLine("go wtime 174448 btime 181053 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5");
		Uci::instance->readLine("go wtime 174448 btime 175070 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3");
		Uci::instance->readLine("go wtime 168637 btime 175070 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3");
		Uci::instance->readLine("go wtime 168637 btime 169288 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3");
		Uci::instance->readLine("go wtime 163019 btime 169288 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8");
		Uci::instance->readLine("go wtime 163019 btime 163700 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5");
		Uci::instance->readLine("go wtime 157589 btime 163700 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4");
		Uci::instance->readLine("go wtime 157589 btime 158296 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4");
		Uci::instance->readLine("go wtime 152340 btime 158296 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6");
		Uci::instance->readLine("go wtime 152340 btime 153073 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2");
		Uci::instance->readLine("go wtime 147265 btime 153073 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5");
		Uci::instance->readLine("go wtime 147265 btime 148020 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2");
		Uci::instance->readLine("go wtime 142358 btime 148020 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5");
		Uci::instance->readLine("go wtime 142358 btime 143138 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3");
		Uci::instance->readLine("go wtime 137618 btime 143138 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4");
		Uci::instance->readLine("go wtime 137618 btime 138421 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4");
		Uci::instance->readLine("go wtime 133035 btime 138421 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4 d8d4");
		Uci::instance->readLine("go wtime 133035 btime 133859 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4 d8d4 d2d4");
		Uci::instance->readLine("go wtime 128603 btime 133859 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4 d8d4 d2d4 f4e2");
		Uci::instance->readLine("go wtime 128603 btime 129450 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4 d8d4 d2d4 f4e2 c1b1");
		Uci::instance->readLine("go wtime 124322 btime 129450 winc 0 binc 0");
		Uci::instance->readLine("position startpos moves e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 c2c4 d6d5 b1c3 f8b4 c1d2 c8e6 c4d5 f6d5 c3d5 b4d2 d1d2 e6d5 d3d4 d5f3 d2e3 e8f8 e3f3 b8c6 e1c1 d8g5 f3e3 g5d5 e3b3 d5b3 a2b3 a8d8 d4d5 c6b4 f1c4 a7a6 d1d2 b7b5 c4e2 b4d5 e2d3 d5f4 d3e4 d8d4 d2d4 f4e2 c1b1 e2d4");
		Search::instance->timeRemaining(124322);
		uint32_t bestMove = Search::instance->iterativeDeepening(Fen::exportBoard());
		cout << "bestmove " << intToBoardCoord(FROM(bestMove)) << intToBoardCoord(TO(bestMove)) << endl;
	}