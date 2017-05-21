#ifndef Evaluation_cpp
#define Evaluation_cpp
	#include "Evaluation.h"

	int Evaluation::terminalPositionValue() {
		if (canTakeKing()) {
			return Board::turn == WHITE ?
				CHECKMATE : -CHECKMATE;
		}
		return STALEMATE;
	}
#endif