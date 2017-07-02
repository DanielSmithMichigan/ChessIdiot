	#include "../src/Search.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"

	using namespace std;

	class SearchTest : public ::testing::Test{
		private:
		public:
			SearchTest();
			~SearchTest();
	};