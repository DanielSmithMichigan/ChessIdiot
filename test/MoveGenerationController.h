	#include "../src/MoveGenerationController.h"
	#include "../src/Fen.h"
	#include "testUtilities.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"

	using namespace std;

	class MoveGenerationControllerTest : public ::testing::Test{
		private:
		public:
			shared_ptr<MoveGenerationController> moveGenerationController;
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
			shared_ptr<AttackedSquare> attackedSquare;
			shared_ptr<Fen> fen;
			MoveGenerationControllerTest();
			~MoveGenerationControllerTest();
	};