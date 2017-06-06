#ifndef Evaluation_cpp
#define Evaluation_cpp
	#include "Evaluation.h"

	int Evaluation::terminalPositionValue() {
		if (kingInCheck()) {
			return CHECKMATE;
		}
		return STALEMATE;
	}

	int Evaluation::positionValue() {
		if (Board::turn == WHITE) {
			return -Board::pieceValue;
		} else {
			return Board::pieceValue;
		}
	}
#endif