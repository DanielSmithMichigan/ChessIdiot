	#include "MoveGenerationController.h"

	MoveGenerationControllerTest::MoveGenerationControllerTest() {
		moveStack = make_shared<MoveStack>();
		board = make_shared<Board>();
		moveGenerationController.reset(new MoveGenerationController(board, moveStack));
	}

	MoveGenerationControllerTest::~MoveGenerationControllerTest() {
	}

	void MoveGenerationControllerTest::SetUp() {
		int newBoardArray[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		copy(begin(newBoardArray), end(newBoardArray), begin(board->squares));
	}

	TEST_F(MoveGenerationControllerTest, RunFirstTest) {
		board->squares[0] = WHITE_KING;
		moveGenerationController->generateMovesAt(0);
		// for(int i = 0; i < 10; i++) {
		// 	cout << "MoveStackEntry: " << i << " IS " << moveStack->stack[i] << endl;
		// }
	}