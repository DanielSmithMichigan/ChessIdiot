#ifndef Board_h
#define Board_h
	#include "globals.h"
	#include "Move.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include <math>
	
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
			int enPassantTarget = SOMEWHERE_OFF_BOARD;
			int blackKingLocation = 0;
			int whiteKingLocation = 0;
			void place(int piece, int location);
			void remove(int location);
			void doMove(uint32_t move);
			void undoMove();
			void undoEnPassant(uint32_t move);
			bool shouldSetEnPassantTarget(uint32_t move);
			void checkAndSetEnPassantTarget();
			void changeTurn();
	};
#endif