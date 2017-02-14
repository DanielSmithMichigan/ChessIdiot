	#include "../src/Fen.h"
	#include "../src/MoveGenerationController.h"
	#include "TestBoard.h"
	#include "TestMoveStack.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include "testUtilities.h"
	#include <algorithm>
	#include <sstream>
	#include <fstream>
	#include <string>
	#include <vector>
	using namespace std;

	class Reconciliation : public ::testing::Test{
		private:
		public:
			shared_ptr<Fen> fen;
			shared_ptr<TestBoard> board;
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<TestMoveStack> moveStack;
			shared_ptr<AttackedSquare> attackedSquare;
			Reconciliation();
			~Reconciliation();
			void executeTestFile(string filename);
	};