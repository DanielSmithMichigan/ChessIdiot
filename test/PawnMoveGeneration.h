	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>

	using namespace std;

	class PawnMoveGeneratorTest : public ::testing::Test{
		private:
		public:
			virtual void SetUp();
			PawnMoveGeneratorTest();
			~PawnMoveGeneratorTest();
	};