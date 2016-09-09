	#include "../src/AttackedSquare.h"
	#include "TestMoveStack.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include <algorithm>

	using namespace std;

	class AttackedSquareTest : public ::testing::Test{
		private:
		public:
			shared_ptr<AttackedSquare> attackedSquare;
			shared_ptr<Board> board;
			AttackedSquareTest();
			~AttackedSquareTest();
	};