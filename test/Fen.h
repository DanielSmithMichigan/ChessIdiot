	#include "../src/Fen.h"
	#include "TestBoard.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include <algorithm>

	using namespace std;

	class FenTest : public ::testing::Test{
		private:
		public:
			shared_ptr<Fen> fen;
			shared_ptr<TestBoard> board;
			FenTest();
			~FenTest();
	};