#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include <stdint.h>
	#include "Fen.h"
	#include "Board.h"
	#include "MoveStack.h"
	#include "Evaluation.h"
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
			void generateAllMoves();
			void generateCaptures();
			uint64_t countMovesAtDepth(uint64_t depth);
			uint32_t getBestMove(int depth);
			int alphaBeta(int alpha, int beta, int depthRemaining);
			int quiescence(int alpha, int beta);
			static MoveGenerationController *instance;
	};
#endif