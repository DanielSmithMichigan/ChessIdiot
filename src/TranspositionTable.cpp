#ifndef TranspositionTable_cpp
#define TranspositionTable_cpp
	#include "TranspositionTable.h"

	TranspositionTable *TranspositionTable::instance = new TranspositionTable();


	TranspositionTable::TranspositionTable() {
	}

	TranspositionTable::~TranspositionTable() {
	}

	void TranspositionTable::reset() {
		if (table != NULL) {
			free(table);
		}
		table = (TranspositionTableEntry*)malloc(TRANSPOSITION_TABLE_SIZE);
		for (int i = 0; i < TRANSPOSITION_TABLE_LENGTH; i++) {
			table[i].reset();
		}
		age = 0;
	}

	void TranspositionTable::store(uint32_t bestMove) {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		table[index].positionKey = Board::currentState->zobrist;
		table[index].bestMove = bestMove;
	}

	uint32_t TranspositionTable::searchMove() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist) {
			return table[index].bestMove;
		}
		return TRANSPOSITION_TABLE_MISS;
	}


#endif