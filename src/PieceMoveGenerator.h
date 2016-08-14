#ifndef PieceMoveGenerator_h
#define PieceMoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include <list>
	#include "utilities.h"
	#include "globals.h"
	#include "Move.h"
	#include "Board.h"

	using namespace std;

	class PieceMoveGenerator {
		private:
		protected:
			shared_ptr<Board> board;
		public:
			bool canSlideNorth = false;
			bool canSlideNorthEast = false;
			bool canSlideEast = false;
			bool canSlideSouthEast = false;
			bool canSlideSouth = false;
			bool canSlideSouthWest = false;
			bool canSlideWest = false;
			bool canSlideNorthWest = false;
			uint64_t moveBoards[8][8][13];
			list<Move> moveLists[8][8][13];
			void generate();
			void generateMoveBoards(int x, int y);
			list<Move> &generateNorthSlide(int x, int y);
			list<Move> &generateNorthEastSlide(int x, int y);
			list<Move> &generateEastSlide(int x, int y);
			list<Move> &generateSouthEastSlide(int x, int y);
			list<Move> &generateSouthSlide(int x, int y);
			list<Move> &generateSouthWestSlide(int x, int y);
			list<Move> &generateWestSlide(int x, int y);
			list<Move> &generateNorthWestSlide(int x, int y);
			list<Move> &generateKnightMoves(int x, int y);
			list<Move> &generatePawnAttackMoves(int x, int y, int color);
			list<Move> &generatePawnForwardMoves(int x, int y, int color);
			uint64_t movesAt(int x, int y);
			bool isValidKnightMove(int x, int y);
			bool onBoard(int x, int y);
			PieceMoveGenerator(shared_ptr<Board> board);
			~PieceMoveGenerator();
	};
#endif