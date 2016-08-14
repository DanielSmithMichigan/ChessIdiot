#ifndef Move_h
#define Move_h
	#include <stdint.h>

	struct Move {
		int x1, y1, x2, y2;
		Move(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
	};
#endif