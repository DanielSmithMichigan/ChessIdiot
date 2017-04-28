#include "Utility.h"
inline int xyToInt(int x, int y) {
	return y * 8 + x;
}
inline uint64_t getPieceBoard(int i) {
	return 0x8000000000000000 >> i;
}
inline uint64_t getPieceBoard(int x, int y) {
	return getPieceBoard(xyToInt(x, y));
}
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