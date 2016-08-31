	#include "KingMoveGenerator.h"

	KingMoveGeneratorTest::KingMoveGeneratorTest() {
		shared_ptr<MoveStack> moveStack(new MoveStack());
		shared_ptr<Board> board(new Board());
		kingMoveGenerator.reset(new KingMoveGenerator(board, moveStack));
	}

	KingMoveGeneratorTest::~KingMoveGeneratorTest() {
	}

	void KingMoveGeneratorTest::run() {
		ASSERT_EQ(2, 2);
		cout << "HELLO" << endl;
	}