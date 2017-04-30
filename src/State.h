#ifndef State_h
#define State_h
	#include <stdint.h>
	struct State {
		uint32_t capturedPiece;
		uint32_t capturedPieceColor;
		uint32_t move;
		State* prev;
	};
#endif

