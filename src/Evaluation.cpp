#ifndef Evaluation_cpp
#define Evaluation_cpp
	#include "Evaluation.h"

	int Evaluation::PieceValue[7] = {
		0, 1, 3, 3, 5, 9, 0
	};

	int Evaluation::terminalPositionValue() {
		if (SquareAttacked::canTakeKing()) {
			return Board::turn == WHITE ?
				CHECKMATE : -CHECKMATE;
		}
		return STALEMATE;
	}
#endif