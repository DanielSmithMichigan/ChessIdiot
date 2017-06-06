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
	#include "TranspositionTable.h"
	

	using namespace std;

	class MoveGenerationController {
		private:
			uint32_t nodesSearched;
			uint32_t bestMove;
			int bestScore;
			int depthSearched;
			int alphaBeta(int alpha, int beta, int depthRemaining);
			int quiescence(int alpha, int beta);
		public:
			MoveGenerationController();
			~MoveGenerationController();
			void reset();
			void showStats();
			uint64_t countMovesAtDepth(uint64_t depth);
			void runAtDepth(uint64_t depth, void (*fn)());
			uint32_t getBestMove(int depth);
			static MoveGenerationController *instance;

			template <bool CAPTURES_ONLY>
			void generateAllMoves() {
				if (Board::turn == WHITE) {
					generatePawnMoves<WHITE, CAPTURES_ONLY>();
					generateBishopMoves<WHITE, CAPTURES_ONLY>();
					generateRookMoves<WHITE, CAPTURES_ONLY>();
					generateQueenMoves<WHITE, CAPTURES_ONLY>();
					generateKnightMoves<WHITE, CAPTURES_ONLY>();
					generateKingMoves<WHITE, CAPTURES_ONLY>();
				} else {
					generatePawnMoves<BLACK, CAPTURES_ONLY>();
					generateBishopMoves<BLACK, CAPTURES_ONLY>();
					generateRookMoves<BLACK, CAPTURES_ONLY>();
					generateQueenMoves<BLACK, CAPTURES_ONLY>();
					generateKnightMoves<BLACK, CAPTURES_ONLY>();
					generateKingMoves<BLACK, CAPTURES_ONLY>();
				}
				MoveStack::instance->scoreSpecialMoves(TranspositionTable::instance->searchMove());
			}
	};
#endif