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

	void TranspositionTable::store(uint32_t bestMove,uint64_t score, uint16_t priority) {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (priority >= table[index].priority) {
			table[index].positionKey = Board::currentState->zobrist;
			table[index].depthSearched = Board::currentState->depth;
			table[index].bestMove = bestMove;
			table[index].score = score;
			table[index].priority = priority;
			table[index].age = age;
		}
	}

	void TranspositionTable::increaseAge() {
		age++;
	}

	uint64_t TranspositionTable::searchScore() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist
			&& table[index].age == age
			&& Board::currentState->depth <= table[index].depthSearched) {
			return table[index].score;
		}
		return TRANSPOSITION_TABLE_MISS;
	}

	uint32_t TranspositionTable::searchMove() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist
			&& table[index].priority == PRINCIPAL_VARIATION) {
			return table[index].bestMove;
		}
		return TRANSPOSITION_TABLE_MISS;
	}


#endif