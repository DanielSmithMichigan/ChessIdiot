#ifndef Utility_h
#define Utility_h
	#include <stdint.h>
	#include <iostream>
	#include <math.h>
	#include "Move.h"
	#include "Globals.h"
	using namespace std;
	inline int xyToInt(int x, int y) {
		return y * 8 + x;
	}
	inline uint64_t getPieceBoard(int i) {
		return 0x8000000000000000 >> i;
	}
	inline uint64_t getPieceBoard(int x, int y) {
		return getPieceBoard(xyToInt(x, y));
	}
	inline uint32_t getEnPassantLocation(const uint32_t &from, const uint32_t &to) {
		return xyToInt(to - ROWS(GET_ROW(to)), GET_ROW(from));
	}
	void showBitBoard(uint64_t bitboard);
	void showMoveBoard(uint32_t move);
	uint64_t generateSlideMove(uint64_t occupancyBoard, uint32_t startLocation, uint32_t deltaX, uint32_t deltaY);
	int countOnes(uint64_t bitboard);
	uint64_t bitBoardFromRows(uint64_t row1, uint64_t row2, uint64_t row3, uint64_t row4, uint64_t row5, uint64_t row6, uint64_t row7, uint64_t row8);
	uint64_t binToDec(uint64_t row);
#endif