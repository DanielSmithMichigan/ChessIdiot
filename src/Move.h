#ifndef Move_h
#define Move_h
	#include <stdint.h>
	#define FROM(m) (m & 0x40)
	#define TO(m) ((m >> 6) & 0x40)
	#define PIECE(m) ((m >> 12) & 0xF)
	#define MOVE_TYPE(m) ((m >> 15) & 0x4)
	enum MoveType {
		CAPTURE, PROMOTION, QUIET
	};
	inline uint32_t quietMove(uint8_t from, uint8_t to);
	
	template <MoveType MOVE_TYPE>
	inline uint32_t move(uint8_t from, uint8_t to, uint8_t piece);
#endif

