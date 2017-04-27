#ifndef Utility_h
#define Utility_h
	#include <stdint.h>
	#include <iostream>
	using namespace std;
	inline uint8_t xyToInt(uint8_t x, uint8_t y) {
		return y * 8 + x;
	}
#endif