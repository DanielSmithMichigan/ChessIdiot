	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "../src/MoveStack.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>
	#include <sstream>
	#include <fstream>
	#include <string>
	#include <vector>

	using namespace std;

	class EngineComparison : public ::testing::Test{
		private:
			Fen* fen;
		public:
			virtual void SetUp();
			EngineComparison();
			~EngineComparison();
			void executeTestFile(string filename);
	};