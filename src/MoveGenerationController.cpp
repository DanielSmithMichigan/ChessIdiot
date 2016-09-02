#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController::MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) :
		board(board),
		moveStack(moveStack) {
		rookMoveGenerator.reset(new RookMoveGenerator(board, moveStack));
		knightMoveGenerator.reset(new KnightMoveGenerator(board, moveStack));
		bishopMoveGenerator.reset(new BishopMoveGenerator(board, moveStack));
		queenMoveGenerator.reset(new QueenMoveGenerator(board, moveStack));
		pawnMoveGenerator.reset(new PawnMoveGenerator(board, moveStack));
		kingMoveGenerator.reset(new KingMoveGenerator(board, moveStack));
	}

	MoveGenerationController::~MoveGenerationController() {

	}

	void MoveGenerationController::generateMovesAt(int from) {
		int pieceAtLocation = board->squares[from];
		switch(pieceAtLocation) {
			case WHITE_KING:
			case BLACK_KING:
				kingMoveGenerator->generateMoves(from);
			case EMPTY_SPACE:
				break;
		}
	}

#endif