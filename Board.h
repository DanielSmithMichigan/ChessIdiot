#ifndef Board_h
#define Board_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>

	using namespace std;

	class Board {
		private:
			uint64_t WhitePawns;
			uint64_t WhiteRooks;
			uint64_t WhiteKnights;
			uint64_t WhiteBishops;
			uint64_t WhiteQueens;
			uint64_t WhiteKings;
			uint64_t BlackPawns;
			uint64_t BlackRooks;
			uint64_t BlackKnights;
			uint64_t BlackBishops;
			uint64_t BlackQueens;
			uint64_t BlackKings;
			uint64_t OccupiedSpace;
			uint64_t WhitePieces;
			uint64_t BlackPieces;
		public:
			Board();
			~Board();
			void place(uint8_t color, uint8_t type, uint64_t location);
			uint64_t& getPieceBoard(uint8_t color, uint8_t type);
			uint64_t& getColorBoard(uint8_t color);
			vector<unique_ptr<Square>> squares;
	};
#endif