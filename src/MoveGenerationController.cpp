#ifndef MoveGenerationController_cpp
#define MoveGenerationController_cpp
	#include "MoveGenerationController.h"

	MoveGenerationController::MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) :
		board(move(board)),
		moveStack(move(moveStack)) {
		moveGenerators.resize(6);
		moveGenerators[WHITE_ROOK].reset(new RookMoveGenerator(board, moveStack));
		moveGenerators[WHITE_KNIGHT].reset(new KnightMoveGenerator(board, moveStack));
		moveGenerators[WHITE_BISHOP].reset(new BishopMoveGenerator(board, moveStack));
		moveGenerators[WHITE_QUEEN].reset(new QueenMoveGenerator(board, moveStack));
		moveGenerators[WHITE_PAWN].reset(new PawnMoveGenerator(board, moveStack));
		moveGenerators[WHITE_KING].reset(new KingMoveGenerator(board, moveStack));
	}

	MoveGenerationController::~MoveGenerationController() {

	}

#endif