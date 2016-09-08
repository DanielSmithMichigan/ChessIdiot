#ifndef Board_h
#define Board_h
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
			void initializeEnPassant();
		public:
			Board();
			~Board();
			int turn;
			int squares[BOARD_SIZE];
			bool firstMove[BOARD_SIZE];
			bool enPassant[BOARD_SIZE];
			void place(int piece, int location);
			void remove(int location);
			void move(int xBefore, int yBefore, int xAfter, int yAfter);
	};
#endif