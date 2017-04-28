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