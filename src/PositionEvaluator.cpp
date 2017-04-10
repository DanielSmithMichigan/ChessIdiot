#ifndef PositionEvaluator_cpp
#define PositionEvaluator_cpp
	#include "PositionEvaluator.h"

	PositionEvaluator::PositionEvaluator(shared_ptr<Board> board, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		attackedSquare(attackedSquare) {
	}

	PositionEvaluator::~PositionEvaluator() {
	}

	int PositionEvaluator::terminalPositionValue() {
		if (attackedSquare->kingInCheck()) {
			return board->turn == WHITE ?
				CHECKMATE : -CHECKMATE;
		}
		return STALEMATE;
	}

	int PositionEvaluator::piecesValue() {
		return Board::pieceValue;
	}
#endif