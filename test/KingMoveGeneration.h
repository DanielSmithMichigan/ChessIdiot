	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/BitBoard.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>

	using namespace std;

	class KingMoveGenerationTest : public ::testing::Test{
		private:
		public:
			virtual void SetUp();
			KingMoveGenerationTest();
			~KingMoveGenerationTest();
	};