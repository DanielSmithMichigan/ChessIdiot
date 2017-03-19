#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include "Board.h"
	#include "PawnMoveGenerator.h"
	#include "RookMoveGenerator.h"
	#include "KnightMoveGenerator.h"
	#include "BishopMoveGenerator.h"
	#include "QueenMoveGenerator.h"
	#include "KingMoveGenerator.h"
	#include "MoveStack.h"
	#include "PositionEvaluator.h"
	

	using namespace std;

	static uint32_t __DEFAULT_VAL = 0;

	class MoveGenerationController {
		private:
			shared_ptr<AttackedSquare> attackedSquare;
			shared_ptr<Board> board;
			shared_ptr<PositionEvaluator> positionEvaluator;
			shared_ptr<MoveStack> moveStack;
			shared_ptr<RookMoveGenerator> rookMoveGenerator;
			shared_ptr<KnightMoveGenerator> knightMoveGenerator;
			shared_ptr<BishopMoveGenerator> bishopMoveGenerator;
			shared_ptr<QueenMoveGenerator> queenMoveGenerator;
			shared_ptr<PawnMoveGenerator> whitePawnMoveGenerator;
			shared_ptr<PawnMoveGenerator> blackPawnMoveGenerator;
			shared_ptr<KingMoveGenerator> kingMoveGenerator;
		public:
			MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare);
			~MoveGenerationController();
			int alphaBeta(int alpha, int beta, int depthRemaining, uint32_t &bestMove, uint32_t &firstMove = __DEFAULT_VAL, bool highestDepth = true);
			void generateMovesAt(int from);
			void generateAllMoves();
			int maximizeFor = WHITE;
	};
#endif