	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>
	#include <unordered_map>
	#define ALTERNATE_TRANSPOSITION_TABLE_LENGTH 0x200000
	#define ALTERNATE_TRANSPOSITION_TABLE_MASK 0b111111111111111111111
	#define ALTERNATE_TRANSPOSITION_TABLE_SIZE (ALTERNATE_TRANSPOSITION_TABLE_LENGTH * sizeof(AlternateTranspositionTableEntry))

	using namespace std;

	struct AlternateTranspositionTableEntry {
		uint64_t positionKey;
		char fen[100];
		void reset() {
			positionKey = 0ULL;
		}
	};

	class ZobristTest : public ::testing::Test{
		private:
		public:
			static AlternateTranspositionTableEntry *table;
			ZobristTest();
			~ZobristTest();
			static void checkFenToZobrist();
			static void checkZobristToFen();
			void doMove(uint32_t from, uint32_t to);
			void performZobrist(string fenString, uint64_t depth);
			void performZobristOpposite(string fenString, uint64_t depth);
			static void store();
			static void retrieve();
	};