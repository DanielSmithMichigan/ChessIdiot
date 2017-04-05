#ifndef MoveValue_cpp
#define MoveValue_cpp
	#include "MoveValue.h"

	MoveValue::MoveValue(shared_ptr<Board> board) 
		: board(board) {
		reset();
	}

	MoveValue::~MoveValue() {
	}

	void MoveValue::reset() {
		pieceValue[0] = 0;
		pieceValue[1] = 1;
		pieceValue[2] = 3;
		pieceValue[3] = 3;
		pieceValue[4] = 5;
		pieceValue[5] = 9;
		pieceValue[6] = 5;
		pieceValue[7] = 1;
		pieceValue[8] = 3;
		pieceValue[9] = 3;
		pieceValue[10] = 5;
		pieceValue[11] = 9;
		pieceValue[12] = 5;
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				mvvLva[i][j] = (100 * pieceValue[i]) - pieceValue[j];
			}
		}
	}

	int MoveValue::getValue(uint32_t move) {
		return mvvLva
			      [CAPTURED_PIECE(move)]
			      [board->getLocation(FROM(move))];
	}

#endif