#ifndef Board_h
#define Board_h
	#include "Globals.h"
	#include "State.h"
	#include "Move.h"
	#include "Utility.h"
	#include <stdint.h>
	#include <iostream>
	
	#define MAX_MOVES_PLAYED 128

	using namespace std;

	class Board {
		private:
		protected:
		public:
			Board();
			~Board();
			static State* currentState;
			static int pieceValue;
			static void reset();
			static void doMove(uint32_t move);
			static void undoMove();
			static uint32_t turn;
			static void put(uint32_t color, uint32_t piece, uint32_t location);
			static void remove(uint32_t color, uint32_t piece, uint32_t location);
			static uint32_t getPiece(uint32_t location);
			static uint32_t getColor(uint32_t location);
			static uint64_t occupiedSquares;
			static uint64_t colors[3];
			static uint64_t pieces[8];
			static uint32_t piecesIndex[64];
			static uint32_t colorsIndex[64];
			static int PiecesValue[7];
			static inline void decreaseStateDepth() {
				State *prevState = currentState->prev;
				delete currentState;
				currentState = prevState;
			}
			static inline void increaseStateDepth() {
				State* nextState = new State();
				nextState->prev = currentState;
				nextState->whiteCanCastleLeft = currentState->whiteCanCastleLeft;
				nextState->blackCanCastleLeft = currentState->blackCanCastleLeft;
				nextState->whiteCanCastleRight = currentState->whiteCanCastleRight;
				nextState->blackCanCastleRight = currentState->blackCanCastleRight;
				currentState = nextState;
			}

	};
#endif