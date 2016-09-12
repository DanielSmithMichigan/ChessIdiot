#ifndef MoveGenerator_h
#define MoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include <list>
	#include <vector>
	#include "utilities.h"
	#include "globals.h"
	#include "MoveStack.h"
	#include "AttackedSquare.h"
	#include "Move.h"
	#include "Board.h"

	using namespace std;

	class MoveGenerator {
		private:
			bool canMoveNorth = false;
			bool canMoveNorthEast = false;
			bool canMoveEast = false;
			bool canMoveSouthEast = false;
			bool canMoveSouth = false;
			bool canMoveSouthWest = false;
			bool canMoveWest = false;
			bool canMoveNorthWest = false;
		protected:
		public:
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
			shared_ptr<AttackedSquare> attackedSquare;
			MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack>, shared_ptr<AttackedSquare>);
			~MoveGenerator();
			void generateMoves(int from);
			void generateMove(int from, int to, int promotedPiece = BLANK, int enPassant = BLANK);
			bool isLegal(uint32_t move);
	};
#endif