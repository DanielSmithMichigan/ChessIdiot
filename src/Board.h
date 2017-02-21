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
			void initializePieces();
			vector<uint32_t> movesPlayed;
		public:
			Board();
			~Board();
			int turn;
			int fullMoveClock;
			int halfMoveClock;
			int squares[BOARD_SIZE];
			int enPassantTarget;
			int initialEnPassantTarget;
			int blackKingLocation = 0;
			int whiteKingLocation = 0;
			bool whiteCanCastleLeft = true;
			bool whiteCanCastleRight = true;
			bool blackCanCastleLeft = true;
			bool blackCanCastleRight = true;
			bool initialWhiteCanCastleLeft = true;
			bool initialWhiteCanCastleRight = true;
			bool initialBlackCanCastleLeft = true;
			bool initialBlackCanCastleRight = true;
			void place(int piece, int location);
			void remove(int location);
			void doMove(uint32_t move);
			void undoMove();
			void reset();
			void initializeEmptyBoard();
			void initializeFirstMove();
			void adjustCastlingBooleans(uint32_t move);
			void resetCastlingBooleans(uint32_t move);
			void checkAndUndoEnPassant(uint32_t move);
			bool shouldSetEnPassantTarget(uint32_t move);
			void checkAndSetEnPassantTarget();
			void checkAndPerformEnPassant(uint32_t move);
			void checkAndPerformCastle(uint32_t move);
			void checkAndUndoCastle(uint32_t move);
			void changeTurn();
	};
#endif