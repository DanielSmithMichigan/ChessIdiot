#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController::MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		moveStack(moveStack) {
		rookMoveGenerator.reset(new RookMoveGenerator(board, moveStack, attackedSquare));
		knightMoveGenerator.reset(new KnightMoveGenerator(board, moveStack, attackedSquare));
		bishopMoveGenerator.reset(new BishopMoveGenerator(board, moveStack, attackedSquare));
		queenMoveGenerator.reset(new QueenMoveGenerator(board, moveStack, attackedSquare));
		whitePawnMoveGenerator.reset(new PawnMoveGenerator(board, moveStack, attackedSquare));
		whitePawnMoveGenerator->direction = GET_DIRECTION(WHITE);
		blackPawnMoveGenerator.reset(new PawnMoveGenerator(board, moveStack, attackedSquare));
		blackPawnMoveGenerator->direction = GET_DIRECTION(BLACK);
		kingMoveGenerator.reset(new KingMoveGenerator(board, moveStack, attackedSquare));
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::generateMovesAt(int from) {
		int pieceAtLocation = board->squares[from];
		switch(pieceAtLocation) {
			case WHITE_KING:
			case BLACK_KING:
				kingMoveGenerator->generateMoves(from);
				break;
			case WHITE_KNIGHT:
			case BLACK_KNIGHT:
				knightMoveGenerator->generateMoves(from);
				break;
			case WHITE_BISHOP:
			case BLACK_BISHOP:
				bishopMoveGenerator->generateMoves(from);
				break;
			case WHITE_QUEEN:
			case BLACK_QUEEN:
				queenMoveGenerator->generateMoves(from);
				break;
			case WHITE_ROOK:
			case BLACK_ROOK:
				rookMoveGenerator->generateMoves(from);
				break;
			case WHITE_PAWN:
				whitePawnMoveGenerator->generateMoves(from);
				break;
			case BLACK_PAWN:
				blackPawnMoveGenerator->generateMoves(from);
				break;
			case EMPTY_SPACE:
				break;
		}
	}

#endif