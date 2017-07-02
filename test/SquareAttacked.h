	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "../src/SquareAttacked.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>

	using namespace std;

	class SquareAttackedTest : public ::testing::Test{
		private:
		public:
			virtual void SetUp();
			SquareAttackedTest();
			~SquareAttackedTest();
	};