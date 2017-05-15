#ifndef State_h
#define State_h
	#include <stdint.h>
	struct State {
		uint32_t capturedPiece;
		uint32_t capturedPieceColor;
		uint32_t move;
		uint32_t enPassantTarget = -1;
		bool blackCanCastleLeft = true;
		bool whiteCanCastleLeft = true;
		bool blackCanCastleRight = true;
		bool whiteCanCastleRight = true;
		State* prev = 0;
	};
#endif

