#ifndef State_h
#define State_h
	#include <stdint.h>
	struct State {
		uint32_t capturedPiece;
		uint32_t capturedPieceColor;
		uint32_t move;
		uint32_t enPassantTarget = -1;
		uint8_t castlingRights = 0;
		uint16_t zobrist = 0;
		State* prev = 0;
	};
#endif

