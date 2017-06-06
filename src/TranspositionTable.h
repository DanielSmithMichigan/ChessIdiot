#ifndef TranspositionTable_h
#define TranspositionTable_h
	
	#include "Board.h"
	#include <stdint.h>
	#include <cstddef>
	#define TRANSPOSITION_TABLE_LENGTH 0x200000
	#define TRANSPOSITION_TABLE_MASK 0b111111111111111111111
	#define TRANSPOSITION_TABLE_SIZE (TRANSPOSITION_TABLE_LENGTH * sizeof(TranspositionTableEntry))
	#define TRANSPOSITION_TABLE_MISS -1

	using namespace std;

	struct TranspositionTableEntry {
		uint64_t positionKey;
		uint32_t bestMove;
		uint64_t depthSearched;
		uint64_t score;
		TranspositionTableEntry(uint64_t positionKey,uint32_t bestMove,uint64_t depthSearched,uint64_t score) 
			: positionKey(positionKey), bestMove(bestMove), depthSearched(depthSearched), score(score) {

		}
		TranspositionTableEntry() {

		}
		void reset() {
			positionKey = 0ULL;
			depthSearched = 0;
			score = 0;
			bestMove = 0;
		}
	};

	class TranspositionTable {
		private:
			size_t numEntries;
			TranspositionTableEntry *table;
		protected:
		public:
			static TranspositionTable *instance;
			TranspositionTable();
			~TranspositionTable();
			void reset();
			void store(uint32_t bestMove,uint64_t score);
			int searchScore();
			uint32_t searchMove();
	};



#endif