#ifndef Move_h
#define Move_h
	#include <stdint.h>
	#include <iostream>

	using namespace std;
	#define FROM(m) (m & 0x3F)
	#define TO(m) ((m >> 6) & 0x3F)
	#define PIECE(m) ((m >> 12) & 0xF)
	#define MOVE_TYPE(m) ((m >> 15) & 0x7)
	enum MoveType {
		CAPTURE, PROMOTION, QUIET
	};
	inline uint32_t quietMove(int from, int to);
	
	template <MoveType MOVE_TYPE> inline uint32_t move(uint8_t from, uint8_t to, uint8_t piece);

	inline uint32_t quietMove(int from, int to) {
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
#endif

