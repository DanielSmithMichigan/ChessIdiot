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
		protected:
		public:
			Board();
			~Board();
			int squares[BOARD_SIZE];
			int turn;
			int fullMoveClock;
			int halfMoveClock;
			int enPassantTarget;
			int initialEnPassantTarget;
			int blackKingLocation = 0;
			int whiteKingLocation = 0;
			bool whiteCanCastleLeft = false;
			bool whiteCanCastleRight = false;
			bool blackCanCastleLeft = false;
			bool blackCanCastleRight = false;
			bool initialWhiteCanCastleLeft = false;
			bool initialWhiteCanCastleRight = false;
			bool initialBlackCanCastleLeft = false;
			bool initialBlackCanCastleRight = false;
			void place(int piece, int location);
			void remove(int location);
			void doMove(uint32_t move);
			void undoMove();
			void reset();
			void initializeEmptyBoard();
			void initializeFirstMove();
			void adjustCastlingBooleansTo(uint32_t move);
			void adjustCastlingBooleansFrom(uint32_t move);
			void resetCastlingBooleans(uint32_t move);
			void checkAndUndoEnPassant(uint32_t move);
			bool shouldSetEnPassantTarget(uint32_t move);
			void checkAndSetEnPassantTarget();
			void checkAndPerformEnPassant(uint32_t move);
			void checkAndPerformCastle(uint32_t move);
			void checkAndUndoCastle(uint32_t move);
			void checkAndPerformPromotion(uint32_t move);
			void checkAndUndoPromotion(uint32_t move);
			void changeTurn();
			int getLocation(int location);
	};
#endif