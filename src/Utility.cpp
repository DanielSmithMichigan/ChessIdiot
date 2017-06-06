#ifndef Utility_cpp
#define Utility_cpp
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
			return outputBoard;
		}
	}
	return outputBoard;
}
int countOnes(uint64_t bitboard) {
	uint64_t size = 0;
	while (bitboard) {
		bitboard >>= 1;
		if (bitboard & 1) {
			size++;
		}
	}
	return size;
}
uint64_t bitBoardFromRows(uint64_t row1, uint64_t row2, uint64_t row3, uint64_t row4, uint64_t row5, uint64_t row6, uint64_t row7, uint64_t row8) {
	return binToDec(row8)
		| binToDec(row7) << rows<1>()
		| binToDec(row6) << rows<2>()
		| binToDec(row5) << rows<3>()
		| binToDec(row4) << rows<4>()
		| binToDec(row3) << rows<5>()
		| binToDec(row2) << rows<6>()
		| binToDec(row1) << rows<7>();
}
uint64_t binToDec(uint64_t row) {
	uint64_t output = 0;
	uint64_t mult = 0;
	while (row) {
		if (row & 1) {
			output += pow(2, mult);
		}	
		mult++;
		row /= 10;
	}
	return output;
}

string intToBoardCoord(int location) {
	int row = 8 - GET_ROW(location);
	int column = GET_COLUMN(location);
	string letters[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
	return "" + letters[column] + to_string(row);
}

#endif