#ifndef SquareAttacked_cpp
#define SquareAttacked_cpp
	#include "SquareAttacked.h"

	bool canTakeKing() {
		uint64_t kings = Board::pieces[KING] & Board::colors[OPPOSING_COLOR(Board::turn)];
		uint32_t kingLocation = popBit(kings);
		if (Board::turn == WHITE) {
			return squareAttacked<WHITE>(kingLocation);
		} else {
			return squareAttacked<BLACK>(kingLocation);
		}
	}
#endif