#ifndef BoardValue_cpp
#define BoardValue_cpp
	#include "BoardValue.h"

	BoardValue::BoardValue(shared_ptr<Board> board, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		attackedSquare(attackedSquare) {
	}

	BoardValue::~BoardValue() {
	}

	int BoardValue::get(bool legalMovesExist) {
		if (!legalMovesExist) {
			if (attackedSquare->kingInCheck()) {
				return board->turn * CHECKMATE;
			}
			return STALEMATE;
		}
		return sumOfPieces();
	}

	int BoardValue::sumOfPieces() {
		int sum = 0;
		for (int i = 0; i < BOARD_SIZE; i++) {
			int pieceAtLocation = board->getLocation(i);
			switch(pieceAtLocation) {
				case WHITE_PAWN:
					sum += 1;
				break;
				case BLACK_PAWN:
					sum -= 1;
				break;
				case WHITE_ROOK:
					sum += 5;
				break;
				case BLACK_ROOK:
					sum -= 5;
				break;
				case WHITE_KNIGHT:
					sum += 3;
				break;
				case BLACK_KNIGHT:
					sum -= 3;
				break;
				case WHITE_BISHOP:
					sum += 3;
				break;
				case BLACK_BISHOP:
					sum -= 3;
				break;
				case WHITE_QUEEN:
					sum += 9;
				break;
				case BLACK_QUEEN:
					sum -= 9;
				break;
			}
		}
		return sum;
	}
#endif