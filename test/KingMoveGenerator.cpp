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
		board->place(WHITE_KING, 0);
		board->place(BLACK_KNIGHT, 1);
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
		board->place(WHITE_KING, 0);
		board->place(WHITE_KNIGHT, 1);
		moveGenerationController->generateMovesAt(0);
		EXPECT_EQ(moveStack->top, 2);
		sort(moveStack->stack, moveStack->stack + 2);
		EXPECT_EQ(FROM(moveStack->stack[0]), 0);
		EXPECT_EQ(FROM(moveStack->stack[1]), 0);
		EXPECT_EQ(TO(moveStack->stack[0]), 16);
		EXPECT_EQ(TO(moveStack->stack[1]), 17);
	}

	TEST_F(KingMoveGenerationControllerTest, TopLeft) {
		board->place(WHITE_KING, 0);
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
		board->place(WHITE_KING, 7);
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
		board->place(WHITE_KING, 119);
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
		board->place(WHITE_KING, 112);
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
		board->place(WHITE_KING, 17);
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
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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

	TEST_F(KingMoveGenerationControllerTest, 3rdSquareCannotBeOccupied) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_BISHOP, 113);
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, 3rdSquareCanBeAttacked) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_BISHOP, 96);
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
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

	TEST_F(KingMoveGenerationControllerTest, 2ndSquareCannotBeAttacked) {
		board->place(WHITE_ROOK, 112);
		board->place(WHITE_KING, 116);
		board->place(WHITE_ROOK, 119);
		board->place(BLACK_BISHOP, 97);
		board->whiteCanCastleLeft = true;
		board->whiteCanCastleRight = true;
		moveGenerationController->generateMovesAt(116);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, CastleBlack) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, BlackWillNotMoveThroughPiecesRight) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(BLACK_BISHOP, 6);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, BlackWillNotMoveThroughPiecesLeft) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(BLACK_BISHOP, 3);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, BlackWillNotMoveThroughCheck) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(WHITE_KNIGHT, 36);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, BlackWillNotCastleIfKingIsInCheck) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(WHITE_KNIGHT, 18);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, Black3rdSquareCannotBeOccupied) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(BLACK_BISHOP, 1);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, Black3rdSquareCanBeAttacked) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(WHITE_BISHOP, 16);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}

	TEST_F(KingMoveGenerationControllerTest, Black2ndSquareCannotBeAttacked) {
		board->turn = BLACK;
		board->place(BLACK_ROOK, 0);
		board->place(BLACK_KING, 4);
		board->place(BLACK_ROOK, 7);
		board->place(WHITE_BISHOP, 17);
		board->blackCanCastleLeft = true;
		board->blackCanCastleRight = true;
		moveGenerationController->generateMovesAt(4);
		int expectedBoard[] = {
			0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		EXPECT_TRUE(moveStack->matches(expectedBoard));
	}