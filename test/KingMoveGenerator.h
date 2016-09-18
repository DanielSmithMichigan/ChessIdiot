	#include "../src/MoveGenerationController.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include "TestMoveStack.h"
	#include <algorithm>

	using namespace std;

	class KingMoveGenerationControllerTest : public ::testing::Test{
		private:
		public:
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<Board> board;
			shared_ptr<TestMoveStack> moveStack;
			shared_ptr<AttackedSquare> attackedSquare;
			KingMoveGenerationControllerTest();
			~KingMoveGenerationControllerTest();
	};