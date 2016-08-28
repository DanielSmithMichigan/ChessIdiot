#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include <stdint.h>
	#include <iostream>
	#include "utilities.h"
	#include "globals.h"
	#include <memory>
	#include "Board.h"
	#include "RookMoveGenerator.h"
	#include "KnightMoveGenerator.h"
	#include "BishopMoveGenerator.h"
	#include "QueenMoveGenerator.h"
	

	using namespace std;

	class MoveGenerationController {
		private:
			shared_ptr<Board> board;
			vector<unique_ptr<PieceMoveGenerator>> pieceMoveGenerators;
		public:
			uint64_t getMovesForPieceAt(int x, int y);
			MoveGenerationController(shared_ptr<Board> board);
			~MoveGenerationController();
	};
#endif