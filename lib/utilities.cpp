#ifndef Utilities_cpp
#define Utilities_cpp
	#include "utilities.h"
	bool even(int i) {
		return i % 2 == 0;
	}
	int xyToInt(int x, int y) {
		return (y * 8) + x;
	}
	uint64_t boardFromNumber(int i) {
		return (uint64_t)1 << i;
	}
	uint64_t identityBoardFromXy(int x, int y) {
		return boardFromNumber(xyToInt(x, y));
	}
#endif