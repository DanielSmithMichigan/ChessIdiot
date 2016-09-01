	#include "../src/MoveGenerationController.h"
	#include "gtest/gtest.h"

	using namespace std;

	class MoveGenerationControllerTest : public ::testing::Test{
		private:
		public:
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
			MoveGenerationControllerTest();
			~MoveGenerationControllerTest();
			void SetUp();
	};