	#include "../src/MoveGenerationController.h"
	#include "TestMoveStack.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include <algorithm>

	using namespace std;

	class MoveGeneratorTest : public ::testing::Test{
		private:
		public:
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<Board> board;
			shared_ptr<TestMoveStack> moveStack;
			shared_ptr<AttackedSquare> attackedSquare;
			MoveGeneratorTest();
			~MoveGeneratorTest();
	};