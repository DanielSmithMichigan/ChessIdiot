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

	void TranspositionTable::store(uint32_t bestMove, uint32_t score, uint8_t type, uint8_t remainingSearchDepth) {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		table[index].positionKey = Board::currentState->zobrist;
		table[index].bestMove = bestMove;
		table[index].depthSearched = remainingSearchDepth;
		table[index].score = score;
		table[index].type = type;
	}

	uint32_t TranspositionTable::searchMove() {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist
			&& table[index].type == EXACT) {
			return table[index].bestMove;
		}
		return TRANSPOSITION_TABLE_MISS;
	}

	bool TranspositionTable::searchPosition(uint32_t remainingSearchDepth, int alpha, int beta, int &score) {
		uint32_t index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist
			&& table[index].depthSearched >= remainingSearchDepth) {
			switch(table[index].type) {
				case EXACT:
					if (table[index].score >= beta) {
						score = beta;
					} else {
						score = table[index].score;
					}
					return true;
				case ALPHA:
					if (table[index].score <= alpha) {
						score = alpha;
						return true;
					}
				break;
				case BETA:
					if (table[index].score >= beta) {
						score = beta;
						return true;
					}
				break;
			}
		}
		return false;
	}

	int TranspositionTable::getCounter() {
		int index = Board::currentState->zobrist & TRANSPOSITION_TABLE_MASK;
		if (table[index].positionKey == Board::currentState->zobrist) {
			return table[index].score;
		}
		return 0;
	}

	void TranspositionTable::runEach(void (*fn)(int i, TranspositionTableEntry *entry)) {
		for (int i = 0; i < TRANSPOSITION_TABLE_LENGTH; i++) {
			fn(i, &table[i]);
		}
	}


#endif