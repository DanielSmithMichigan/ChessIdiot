#ifndef Utility_h
#define Utility_h
	#include <stdint.h>
	#include <iostream>
	using namespace std;
	inline int xyToInt(int x, int y);
	inline uint64_t getPieceBoard(int i);
	inline uint64_t getPieceBoard(int x, int y);
	void showBitBoard(uint64_t bitboard);
#endif