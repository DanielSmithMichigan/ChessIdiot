#include "Utility.h"
void showBitBoard(uint64_t bitboard) {
	cout << "@@@@@@@@@@@@@ BITBOARD @@@@@@@@@@@@" << endl;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (bitboard & getPieceBoard(x, y)) {
				cout << "X";
			} else {
				cout << "0";
			}
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@@ BITBOARD @@@@@@@@@@@@" << endl;
}
void showMoveBoard(uint32_t move) {
	cout << "@@@@@@@@@@@@@ MOVEBOARD @@@@@@@@@@@@" << endl;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (xyToInt(x, y) == FROM(move)) {
				cout << "F";
			} else if (xyToInt(x, y) == TO(move)) {
				cout << "T";
			} else {
				cout << "0";
			}
		}
		cout << endl;
	}
	cout << "@@@@@@@@@@@@@ MOVEBOARD @@@@@@@@@@@@" << endl;
}
uint64_t generateSlideMove(uint64_t occupancyBoard, uint32_t location, uint32_t deltaX, uint32_t deltaY) {
	uint64_t outputBoard = 0;
	uint32_t y = GET_ROW(location);
	uint32_t x = GET_COLUMN(location);
	uint64_t newSquareBoard;
	while(true) {
		if (y >= 7 && deltaY == 1) {
			break;
		} else if (y <= 0 && deltaY == -1) {
			break;
		} else if (x >= 7 && deltaX == 1) {
			break;
		} else if (x <= 0 && deltaX == -1) {
			break;
		}
		x += deltaX;
		y += deltaY;
		outputBoard |= getPieceBoard(x, y);
		if (occupancyBoard & outputBoard) {
			break;
		}
	}
	return outputBoard;
}
