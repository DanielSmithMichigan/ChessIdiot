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
	}

	void TranspositionTable::store(uint32_t bestMove,uint64_t score) {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey != Board::currentState->zobrist
			|| Board::currentState->depth > table[index].depthSearched) {
			table[index].positionKey = Board::currentState->zobrist;
			table[index].depthSearched = Board::currentState->depth;
			table[index].bestMove = bestMove;
			table[index].score = score;
		}
	}

	int TranspositionTable::searchScore() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist
			&& table[index].depthSearched >= Board::currentState->depth) {
			return table[index].score;
		}
		return TRANSPOSITION_TABLE_MISS;
	}

	uint32_t TranspositionTable::searchMove() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist) {
			return table[index].bestMove;
		}
		return TRANSPOSITION_TABLE_MISS;
	}


#endif