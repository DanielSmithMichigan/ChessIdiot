	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/BitBoard.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>
	#include <unordered_map>

	using namespace std;

	class ZobristTest : public ::testing::Test{
		private:
			Fen* fen;
		public:
			ZobristTest();
			~ZobristTest();
			static void checkMap();
			void performZobrist(string fenString, uint64_t depth);
	};