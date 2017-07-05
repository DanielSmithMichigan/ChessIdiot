#ifndef Zobrist_cpp
#define Zobrist_cpp
	#include "Zobrist.h"

	void Zobrist::Init() {
        mt19937_64 e2(6005);
    
        uniform_int_distribution<unsigned long long int> dist(0, ULLONG_MAX);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 7; j++) {
				for (int k = 0; k < 64; k++) {
					PieceBySquare[i][j][k] = dist(e2);
				}
			}
		}

		BlackToMove = dist(e2);

		for (int i = 0; i < 16; i++) {
			CastlingRights[i] = dist(e2);
		}

		for (int i = 0; i < 64; i++) {
			EnPassant[i] = dist(e2);
		}
	}

	uint64_t Zobrist::PieceBySquare[2][7][64] = {0};

	uint64_t Zobrist::BlackToMove = 0;

	uint64_t Zobrist::CastlingRights[16] = {0};

	uint64_t Zobrist::EnPassant[64] = {0};
	
#endif