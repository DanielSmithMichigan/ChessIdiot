	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/BitBoard.h"
	#include "../src/TranspositionTable.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>

	using namespace std;

	class TranspositionTableTest : public ::testing::Test{
		private:
		public:
			TranspositionTableTest();
			~TranspositionTableTest();
	};