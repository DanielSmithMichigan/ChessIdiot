	#include "../src/MoveGenerationController.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include <algorithm>

	using namespace std;

	class KingMoveGenerationControllerTest : public ::testing::Test{
		private:
		public:
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
			KingMoveGenerationControllerTest();
			~KingMoveGenerationControllerTest();
			void SetUp();
	};