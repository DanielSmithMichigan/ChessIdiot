#ifndef Move_h
#define Move_h
	#include <stdint.h>
	#include <iostream>

	using namespace std;
	#define FROM(m) (m & 0x3F)
	#define TO(m) ((m >> 6) & 0x3F)
	#define SPECIAL_MOVE(m) ((m >> 12) & 0x7)
	#define PIECE(m) ((m >> 15) & 0xF)
	enum SpecialMove {
		CLASSIC, PROMOTION, EN_PASSANT, PAWN_DOUBLE, CASTLE
	};

	inline uint32_t quietMove(const int &from, const int &to);
	
	template <SpecialMove MOVE_TYPE> inline uint32_t move(const uint32_t &from, const uint32_t &to, const uint32_t &piece);
	
	template <SpecialMove MOVE_TYPE> inline uint32_t move(const uint32_t &from, const uint32_t &to);

	inline uint32_t quietMove(const int &from, const int &to) {
		return from | (to << 6);
	}

	template <SpecialMove MOVE_TYPE>
	inline uint32_t move(const uint32_t &from, const uint32_t &to, const uint32_t &piece) {
		return (piece << 15) | (MOVE_TYPE << 12) | quietMove(from, to);
	}

	template <SpecialMove MOVE_TYPE>
	inline uint32_t move(const uint32_t &from, const uint32_t &to) {
		return (MOVE_TYPE << 12) | quietMove(from, to);
	}
#endif

