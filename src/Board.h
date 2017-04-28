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
			static void reset();
			static void doMove(uint32_t move);
			static void undoMove();
			static uint32_t turn;
			static void put(bool color, uint32_t piece, uint32_t location);
			static void remove(bool color, uint32_t piece, uint32_t location);
			static uint32_t getPiece(uint32_t location);
			static uint32_t getColor(uint32_t location);
			static uint64_t occupiedSquares;
			static uint64_t colors[2];
			static uint64_t pieces[8];
			static uint32_t piecesIndex[64];
			static uint32_t colorsIndex[64];

	};
#endif