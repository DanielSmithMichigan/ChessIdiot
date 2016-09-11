#ifndef Board_h
#define Board_h
	#include "globals.h"
	#include "Move.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	
	#define MAX_MOVES_PLAYED 128

	using namespace std;

	class Board {
		private:
			void initializeEmptyBoard();
			void initializePieces();
			void initializeFirstMove();
			void initializeEnPassant();
			vector<uint32_t> movesPlayed;
		public:
			Board();
			~Board();
			int turn;
			int squares[BOARD_SIZE];
			int firstMove[BOARD_SIZE];
			int enPassant[BOARD_SIZE];
			int blackKingLocation = 0;
			int whiteKingLocation = 0;
			void place(int piece, int location);
			void remove(int location);
			void doMove(uint32_t move);
			void undoMove();
			void changeTurn();
	};
#endif