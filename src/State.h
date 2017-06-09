#ifndef State_h
#define State_h
	#include "Globals.h"
	#include <stdint.h>
	struct State {
		uint32_t capturedPiece;
		uint32_t capturedPieceColor;
		uint32_t move;
		uint32_t enPassantTarget = NO_EN_PASSANT;
		uint8_t castlingRights = 0;
		uint64_t zobrist = 0;
		int depth = 0;
		State* prev = 0;
	};
#endif

