	#include "../src/MoveStack.h"
	#include "../src/Board.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <memory>

	using namespace std;

	class MoveStackTest : public ::testing::Test{
		private:
		public:
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
			MoveStackTest();
			~MoveStackTest();
	};