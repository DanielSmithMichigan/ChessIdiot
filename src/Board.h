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
			uint64_t occupiedSpace = 0;
			uint64_t pieceBoards[2][6];
			uint64_t colorBoards[2];
			void initialize();
		public:
			Board();
			~Board();
			void place(uint64_t color, uint64_t type, int x, int y);
			void remove(uint64_t color, uint64_t type, int x, int y);
			void move(int xBefore, int yBefore, int xAfter, int yAfter);
			void removeIndicatorColors();
			void highlightAllMatches(uint64_t bitboard);
			uint64_t getPieceAtSquare(int x, int y);
			vector<vector<unique_ptr<Square>>> squares;
	};
#endif