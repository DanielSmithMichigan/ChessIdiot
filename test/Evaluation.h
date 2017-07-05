	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "../src/Init.h"
	#include "TestUtility.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <algorithm>
	#include <unordered_map>

	using namespace std;

	class EvaluationTest : public ::testing::Test{
		private:
			static unordered_map<string, int> fenToEvaluation;
		public:
			virtual void SetUp();
			EvaluationTest();
			~EvaluationTest();
			static void checkFenToEvaluation();
			void performEvaluationPerft(string fenString, uint64_t depth);
	};