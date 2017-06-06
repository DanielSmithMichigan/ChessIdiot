	#include "TranspositionTable.h"

	TranspositionTableTest::TranspositionTableTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		TranspositionTable::instance->reset();
		Board::reset();
	}

	TranspositionTableTest::~TranspositionTableTest() {
	}

	TEST_F(TranspositionTableTest, EmptySet) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		ASSERT_EQ(TranspositionTable::instance->searchMove(), TRANSPOSITION_TABLE_MISS);
	}

	TEST_F(TranspositionTableTest, BestMove) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, PRINCIPAL_VARIATION);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), firstMove);
	}

	TEST_F(TranspositionTableTest, OverWrite) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, PRINCIPAL_VARIATION);
		uint32_t secondMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(secondMove, 1000, PRINCIPAL_VARIATION);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), secondMove);
	}

	TEST_F(TranspositionTableTest, OverWriteTwo) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, SCORE);
		uint32_t secondMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(secondMove, 1000, PRINCIPAL_VARIATION);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), secondMove);
	}

	TEST_F(TranspositionTableTest, DontOverwite) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, PRINCIPAL_VARIATION);
		uint32_t secondMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(secondMove, 1000, SCORE);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), firstMove);
	}


	TEST_F(TranspositionTableTest, EmptySetTwo) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, PRINCIPAL_VARIATION);
		Board::doMove(firstMove);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), TRANSPOSITION_TABLE_MISS);
	}


	TEST_F(TranspositionTableTest, EmptySetAge) {
		Fen::import("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		TranspositionTable::instance->store(firstMove, 1000, SCORE);
		Board::doMove(firstMove);
		ASSERT_EQ(TranspositionTable::instance->searchMove(), TRANSPOSITION_TABLE_MISS);
	}