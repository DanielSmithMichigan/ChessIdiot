	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/BitBoard.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>

	using namespace std;

	class PerftTest : public ::testing::Test{
		private:
			Fen* fen;
		public:
			virtual void SetUp();
			PerftTest();
			~PerftTest();
			void performPerft(string fen, uint64_t depth, uint64_t nodes);
	};