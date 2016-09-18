	#include "KingMoveGenerator.h"

	KingMoveGenerationControllerTest::KingMoveGenerationControllerTest() {
		moveStack = make_shared<TestMoveStack>();
		board = make_shared<Board>();
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
	}

	KingMoveGenerationControllerTest::~KingMoveGenerationControllerTest() {
	}

	TEST_F(KingMoveGenerationControllerTest, WillTakeBlackPiece) {
		board->squares[0] = WHITE_KING;
		board->squares[1] = BLACK_KNIGHT;
		moveGenerationController->generateMovesAt(0);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3, sortByFrom);
		EXPECT_EQ(FROM(moveStack->stack[0]), 0);
		EXPECT_EQ(FROM(moveStack->stack[1]), 0);
		EXPECT_EQ(FROM(moveStack->stack[2]), 0);
		sort(moveStack->stack, moveStack->stack + 3, sortByTo);
		EXPECT_EQ(TO(moveStack->stack[0]), 1);
		EXPECT_EQ(TO(moveStack->stack[1]), 16);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
	}

	TEST_F(KingMoveGenerationControllerTest, WillNotTakeWhitePiece) {
		board->squares[0] = WHITE_KING;
		board->squares[1] = WHITE_KNIGHT;
		moveGenerationController->generateMovesAt(0);
		EXPECT_EQ(moveStack->top, 2);
		sort(moveStack->stack, moveStack->stack + 2);
		EXPECT_EQ(FROM(moveStack->stack[0]), 0);
		EXPECT_EQ(FROM(moveStack->stack[1]), 0);
		EXPECT_EQ(TO(moveStack->stack[0]), 16);
		EXPECT_EQ(TO(moveStack->stack[1]), 17);
	}

	TEST_F(KingMoveGenerationControllerTest, TopLeft) {
		board->squares[0] = WHITE_KING;
		moveGenerationController->generateMovesAt(0);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3);
		EXPECT_EQ(FROM(moveStack->stack[0]), 0);
		EXPECT_EQ(FROM(moveStack->stack[1]), 0);
		EXPECT_EQ(FROM(moveStack->stack[2]), 0);
		EXPECT_EQ(TO(moveStack->stack[0]), 1);
		EXPECT_EQ(TO(moveStack->stack[1]), 16);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
	}

	TEST_F(KingMoveGenerationControllerTest, TopRight) {
		board->squares[7] = WHITE_KING;
		moveGenerationController->generateMovesAt(7);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3);
		EXPECT_EQ(FROM(moveStack->stack[0]), 7);
		EXPECT_EQ(FROM(moveStack->stack[1]), 7);
		EXPECT_EQ(FROM(moveStack->stack[2]), 7);
		EXPECT_EQ(TO(moveStack->stack[0]), 6);
		EXPECT_EQ(TO(moveStack->stack[1]), 22);
		EXPECT_EQ(TO(moveStack->stack[2]), 23);
	}

	TEST_F(KingMoveGenerationControllerTest, BottomRight) {
		board->squares[119] = WHITE_KING;
		moveGenerationController->generateMovesAt(119);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3);
		EXPECT_EQ(FROM(moveStack->stack[0]), 119);
		EXPECT_EQ(FROM(moveStack->stack[1]), 119);
		EXPECT_EQ(FROM(moveStack->stack[2]), 119);
		EXPECT_EQ(TO(moveStack->stack[0]), 102);
		EXPECT_EQ(TO(moveStack->stack[1]), 103);
		EXPECT_EQ(TO(moveStack->stack[2]), 118);
	}

	TEST_F(KingMoveGenerationControllerTest, BottomLeft) {
		board->squares[112] = WHITE_KING;
		moveGenerationController->generateMovesAt(112);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3);
		EXPECT_EQ(FROM(moveStack->stack[0]), 112);
		EXPECT_EQ(FROM(moveStack->stack[1]), 112);
		EXPECT_EQ(FROM(moveStack->stack[2]), 112);
		EXPECT_EQ(TO(moveStack->stack[0]), 96);
		EXPECT_EQ(TO(moveStack->stack[1]), 97);
		EXPECT_EQ(TO(moveStack->stack[2]), 113);
	}

	TEST_F(KingMoveGenerationControllerTest, KingInMiddle) {
		board->squares[17] = WHITE_KING;
		moveGenerationController->generateMovesAt(17);
		EXPECT_EQ(moveStack->top, 8);
		sort(moveStack->stack, moveStack->stack + 8);
		EXPECT_EQ(FROM(moveStack->stack[0]), 17);
		EXPECT_EQ(FROM(moveStack->stack[1]), 17);
		EXPECT_EQ(FROM(moveStack->stack[2]), 17);
		EXPECT_EQ(FROM(moveStack->stack[3]), 17);
		EXPECT_EQ(FROM(moveStack->stack[4]), 17);
		EXPECT_EQ(FROM(moveStack->stack[5]), 17);
		EXPECT_EQ(FROM(moveStack->stack[6]), 17);
		EXPECT_EQ(FROM(moveStack->stack[7]), 17);
		EXPECT_EQ(TO(moveStack->stack[0]), 0);
		EXPECT_EQ(TO(moveStack->stack[1]), 1);
		EXPECT_EQ(TO(moveStack->stack[2]), 2);
		EXPECT_EQ(TO(moveStack->stack[3]), 16);
		EXPECT_EQ(TO(moveStack->stack[4]), 18);
		EXPECT_EQ(TO(moveStack->stack[5]), 32);
		EXPECT_EQ(TO(moveStack->stack[6]), 33);
		EXPECT_EQ(TO(moveStack->stack[7]), 34);
	}

	TEST_F(KingMoveGenerationControllerTest, CastleWhite) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, WillNotMoveThroughPiecesRight) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_KNIGHT, 117);
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, WillNotMoveThroughPiecesLeft) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_KNIGHT, 115);
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, WillNotMoveThroughCheck) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_KNIGHT, 84);
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, WillNotCastleIfKingIsInCheck) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_KNIGHT, 98);
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}