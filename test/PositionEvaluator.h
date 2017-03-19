	#include "../src/PositionEvaluator.h"
	#include "../src/AttackedSquare.h"
	#include "../src/Board.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"

	using namespace std;

	class PositionEvaluatorTest : public ::testing::Test{
		private:
		public:
			shared_ptr<PositionEvaluator> positionEvaluator;
			shared_ptr<Board> board;
			shared_ptr<AttackedSquare> attackedSquare;
			PositionEvaluatorTest();
			~PositionEvaluatorTest();
	};