#ifndef Utilities_h
#define Utilities_h
	#include <stdint.h>
	#include "Move.h"
	bool even(int i);
	int xyToInt(int x, int y);
	uint64_t boardFromNumber(int i);
	uint64_t identityBoardFromXy(int x, int y);
	uint64_t inverseIdentityBoardFromXy(int x, int y);
	uint64_t opposingColor(uint64_t color);
#endif