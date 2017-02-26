	#include "../src/BoardValue.h"
	#include "../src/AttackedSquare.h"
	#include "../src/Board.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"

	using namespace std;

	class BoardValueTest : public ::testing::Test{
		private:
		public:
			shared_ptr<BoardValue> boardValue;
			shared_ptr<Board> board;
			shared_ptr<AttackedSquare> attackedSquare;
			BoardValueTest();
			~BoardValueTest();
	};