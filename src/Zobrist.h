#ifndef Zobrist_h
#define Zobrist_h

	#include <stdint.h>
    #include <random>
    #include <cmath>
    #include <climits>

	using namespace std;

	namespace Zobrist {
		extern uint64_t PieceBySquare[2][7][64];
		extern uint64_t BlackToMove;
		extern uint64_t CastlingRights[16];
		extern uint64_t EnPassant[8];

		void Init();
	}



#endif