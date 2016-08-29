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
			void initializeEmptyBoard();
			void initializePieces();
			void initializeFirstMove();
		public:
			Board();
			~Board();
			int squares[BOARD_SIZE];
			int firstMove[BOARD_SIZE];
			void place(int piece, int location);
			void remove(int location);
			void move(int xBefore, int yBefore, int xAfter, int yAfter);
			void removeIndicatorColors();
			void doForAllMatches(int x, int y, int action);
			void doForAllMatches(uint64_t bitboard, int action);
			int getPieceAtSquare(int x, int y);
	};
#endif