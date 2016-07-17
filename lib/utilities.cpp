#ifndef Utilities_cpp
#define Utilities_cpp
	#include "utilities.h"
	bool even(int i) {
		return i % 2 == 0;
	}
	int xyToInt(int x, int y) {
		return (y * 8) + x;
	}
#endif