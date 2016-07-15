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
			uint64_t WhitePawns = 0;
			uint64_t WhiteRooks = 0;
			uint64_t WhiteKnights = 0;
			uint64_t WhiteBishops = 0;
			uint64_t WhiteQueens = 0;
			uint64_t WhiteKings = 0;
			uint64_t BlackPawns = 0;
			uint64_t BlackRooks = 0;
			uint64_t BlackKnights = 0;
			uint64_t BlackBishops = 0;
			uint64_t BlackQueens = 0;
			uint64_t BlackKings = 0;
			uint64_t OccupiedSpace = 0;
			uint64_t WhitePieces = 0;
			uint64_t BlackPieces = 0;
		public:
			Board();
			~Board();
			void reset();
			void place(uint8_t color, uint8_t type, uint64_t location);
			void removeIndicatorColors();
			uint64_t& getPieceBoard(uint8_t color, uint8_t type);
			uint64_t& getColorBoard(uint8_t color);
			vector<unique_ptr<Square>> squares;
	};
#endif