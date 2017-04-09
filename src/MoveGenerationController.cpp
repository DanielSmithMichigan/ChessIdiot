#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"
	#define _generateMovesAt(i) \
	pieceAtLocation = Board::squares[i]; \
	if (pieceAtLocation != EMPTY_SPACE \
		&& GET_COLOR(pieceAtLocation) == board->turn) { \
		generateMovesAt(i); \
	}

	MoveGenerationController::MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		moveStack(moveStack),
		attackedSquare(attackedSquare) {
		positionEvaluator.reset(new PositionEvaluator(board, attackedSquare));
		rookMoveGenerator.reset(new RookMoveGenerator(board, moveStack, attackedSquare));
		knightMoveGenerator.reset(new KnightMoveGenerator(board, moveStack, attackedSquare));
		bishopMoveGenerator.reset(new BishopMoveGenerator(board, moveStack, attackedSquare));
		queenMoveGenerator.reset(new QueenMoveGenerator(board, moveStack, attackedSquare));
		whitePawnMoveGenerator.reset(new PawnMoveGenerator(board, moveStack, attackedSquare));
		whitePawnMoveGenerator->direction = GET_DIRECTION(WHITE);
		blackPawnMoveGenerator.reset(new PawnMoveGenerator(board, moveStack, attackedSquare));
		blackPawnMoveGenerator->direction = GET_DIRECTION(BLACK);
		kingMoveGenerator.reset(new KingMoveGenerator(board, moveStack, attackedSquare));
		fen.reset(new Fen(board));
		moveGenerators[WHITE_KING] = kingMoveGenerator;
		moveGenerators[BLACK_KING] = kingMoveGenerator;
		moveGenerators[WHITE_KNIGHT] = knightMoveGenerator;
		moveGenerators[BLACK_KNIGHT] = knightMoveGenerator;
		moveGenerators[WHITE_BISHOP] = bishopMoveGenerator;
		moveGenerators[BLACK_BISHOP] = bishopMoveGenerator;
		moveGenerators[WHITE_QUEEN] = queenMoveGenerator;
		moveGenerators[BLACK_QUEEN] = queenMoveGenerator;
		moveGenerators[WHITE_ROOK] = rookMoveGenerator;
		moveGenerators[BLACK_ROOK] = rookMoveGenerator;
		moveGenerators[WHITE_PAWN] = whitePawnMoveGenerator;
		moveGenerators[BLACK_PAWN] = blackPawnMoveGenerator;
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::generateMovesAt(int from) {
		int pieceAtLocation = Board::squares[from];
		if (pieceAtLocation != EMPTY_SPACE) {
			moveGenerators[pieceAtLocation]->generateMoves(from);
		}
	}

	void MoveGenerationController::generateAllMoves() {
		int pieceAtLocation;
		_generateMovesAt(0)
		_generateMovesAt(1)
		_generateMovesAt(2)
		_generateMovesAt(3)
		_generateMovesAt(4)
		_generateMovesAt(5)
		_generateMovesAt(6)
		_generateMovesAt(7)

		_generateMovesAt(16)
		_generateMovesAt(17)
		_generateMovesAt(18)
		_generateMovesAt(19)
		_generateMovesAt(20)
		_generateMovesAt(21)
		_generateMovesAt(22)
		_generateMovesAt(23)

		_generateMovesAt(32)
		_generateMovesAt(33)
		_generateMovesAt(34)
		_generateMovesAt(35)
		_generateMovesAt(36)
		_generateMovesAt(37)
		_generateMovesAt(38)
		_generateMovesAt(39)

		_generateMovesAt(48)
		_generateMovesAt(49)
		_generateMovesAt(50)
		_generateMovesAt(51)
		_generateMovesAt(52)
		_generateMovesAt(53)
		_generateMovesAt(54)
		_generateMovesAt(55)

		_generateMovesAt(64)
		_generateMovesAt(65)
		_generateMovesAt(66)
		_generateMovesAt(67)
		_generateMovesAt(68)
		_generateMovesAt(69)
		_generateMovesAt(70)
		_generateMovesAt(71)

		_generateMovesAt(80)
		_generateMovesAt(81)
		_generateMovesAt(82)
		_generateMovesAt(83)
		_generateMovesAt(84)
		_generateMovesAt(85)
		_generateMovesAt(86)
		_generateMovesAt(87)

		_generateMovesAt(96)
		_generateMovesAt(97)
		_generateMovesAt(98)
		_generateMovesAt(99)
		_generateMovesAt(100)
		_generateMovesAt(101)
		_generateMovesAt(102)
		_generateMovesAt(103)

		_generateMovesAt(112)
		_generateMovesAt(113)
		_generateMovesAt(114)
		_generateMovesAt(115)
		_generateMovesAt(116)
		_generateMovesAt(117)
		_generateMovesAt(118)
		_generateMovesAt(119)
		moveStack->sortCurrentDepth();
	}

	uint32_t MoveGenerationController::getBestMove(int depth) {
		generateAllMoves();
		int bestScore = INT32_MIN;
		int bestMove = 0;
		while(uint32_t currentMove = moveStack->pop()) {
			board->doMove(currentMove);
			if (attackedSquare->kingInCheck(GET_OPPOSING_COLOR(board->turn))) {
				board->undoMove();
				continue;
			}
			moveStack->increaseDepth();
			int score = -alphaBeta(INT16_MIN + 1, INT16_MAX, depth - 1);
			moveStack->decreaseDepth();
			board->undoMove();
			if (score > bestScore) {
				bestScore = score;
				bestMove = currentMove;
			} 
		}
		return bestMove;
	}

	int MoveGenerationController::alphaBeta(int alpha, int beta, int depthRemaining) {
		if (depthRemaining == 0) {
			return positionEvaluator->piecesValue();
		}
		generateAllMoves();
		int legalMoves = 0;
		while(uint32_t currentMove = moveStack->pop()) {
			board->doMove(currentMove);
			if (attackedSquare->kingInCheck(GET_OPPOSING_COLOR(board->turn))) {
				board->undoMove();
				continue;
			}
			legalMoves++;
			moveStack->increaseDepth();
			int score = -alphaBeta(-beta, -alpha, depthRemaining - 1);
			moveStack->decreaseDepth();
			board->undoMove();
			if (score >= beta) {
				return beta; 
			} else if (score > alpha) {
				alpha = score;
			}
		}

		if (legalMoves == 0) {
			return positionEvaluator->terminalPositionValue();
		}

		return alpha;
	}

#endif