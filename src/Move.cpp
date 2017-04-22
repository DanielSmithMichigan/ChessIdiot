#include "Move.h"

inline uint32_t quietMove(uint8_t from, uint8_t to) {
	return from | (to << 6);
}

template <MoveType MOVE_TYPE>
inline uint32_t move(uint8_t from, uint8_t to, uint8_t piece) {
	if (MOVE_TYPE == QUIET) {
		return quietMove(from, to);
	} else {
		return (MOVE_TYPE << 15) | (piece << 12) | quietMove(from, to);
	}
}

