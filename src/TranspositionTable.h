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

	enum TRANSPOSITION_TABLE_TYPE {
		ALPHA,
		BETA,
		EXACT,
	};

	struct TranspositionTableEntry {
		uint8_t depthSearched;
		uint64_t positionKey;
		uint32_t bestMove;
		int score;
		uint8_t type;
		void reset() {
			positionKey = 0ULL;
			bestMove = 0;
			depthSearched = 0;
			score = 0;
			type = 0;
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
			void store(uint32_t bestMove, int score, uint8_t type, uint8_t remainingSearchDepth);
			uint32_t searchMove();
			bool searchPosition(uint32_t remainingSearchDepth, int alpha, int beta, int &score);
			int getCounter();
			void runEach(void (*fn)(int i, TranspositionTableEntry *entry));
	};



#endif