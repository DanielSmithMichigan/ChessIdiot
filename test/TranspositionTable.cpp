	#include "TranspositionTable.h"

	TranspositionTableTest::TranspositionTableTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		TranspositionTable::instance->reset();
		Board::reset();
	}

	TranspositionTableTest::~TranspositionTableTest() {
	}

	TEST_F(TranspositionTableTest, SizeTest) {
		for (uint32_t i = 0; i < ULONG_MAX; i++) {
			TranspositionTable::instance->store(i, 1);
		}
	}