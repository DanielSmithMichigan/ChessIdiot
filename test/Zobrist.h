	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>
	#include <unordered_map>

	using namespace std;

	class ZobristTest : public ::testing::Test{
		private:
		public:
			ZobristTest();
			~ZobristTest();
			static void checkFenToZobrist();
			static void checkZobristToFen();
			void doMove(uint32_t from, uint32_t to);
			void performZobrist(string fenString, uint64_t depth);
			void performZobristOpposite(string fenString, uint64_t depth);
	};