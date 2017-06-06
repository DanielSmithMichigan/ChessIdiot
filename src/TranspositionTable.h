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

	enum TRANSPOSITION_TABLE_PRIORITY {
		PRINCIPAL_VARIATION = 1,
		SCORE = 0
	};

	struct TranspositionTableEntry {
		uint64_t positionKey;
		uint32_t bestMove;
		int score;
		uint16_t depthSearched;
		uint16_t priority;
		void reset() {
			positionKey = 0ULL;
			bestMove = 0;
		}
	};

	class TranspositionTable {
		private:
			size_t numEntries;
			TranspositionTableEntry *table;
			uint16_t age;
		protected:
		public:
			static TranspositionTable *instance;
			TranspositionTable();
			~TranspositionTable();
			void reset();
			void store(uint32_t bestMove);
			int searchScore(int depthRemaining);
			uint32_t searchMove();
	};



#endif