#ifndef Lsb_h
#define Lsb_h
	#include "stdint.h"
	const int index64[64] = {63,16,62,7,15,36,61,3,6,14,22,26,35,47,60,2,9,5,28,11,13,21,42,19,25,31,34,40,46,52,59,1,17,8,37,4,23,27,48,10,29,12,43,20,32,41,53,18,38,24,49,30,44,33,54,39,50,45,55,51,56,57,58,0};
	static uint8_t bitScanForward(uint64_t bitboard) {
		const uint64_t debruijn64 = 0x03f79d71b4cb0a89;
		return index64[((bitboard ^ (bitboard-1)) * debruijn64) >> 58];
	}
	static uint8_t popBit(uint64_t &bitboard) {
		uint8_t index = bitScanForward(bitboard);
		bitboard &= bitboard - 1;
		return index;
	}
#endif