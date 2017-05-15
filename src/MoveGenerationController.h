#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include <stdint.h>
	#include "Fen.h"
	#include "Board.h"
	#include "MoveStack.h"
	#include "PawnMoveGeneration.h"
	#include "BishopMoveGeneration.h"
	#include "RookMoveGeneration.h"
	#include "QueenMoveGeneration.h"
	#include "KnightMoveGeneration.h"
	#include "KingMoveGeneration.h"
	

	using namespace std;

	class MoveGenerationController {
		private:
		public:
			MoveGenerationController();
			~MoveGenerationController();
			static void generateAllMoves();
			static uint64_t countMovesAtDepth(uint64_t depth);
	};
#endif