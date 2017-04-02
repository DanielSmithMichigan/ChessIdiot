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
	#include "Fen.h"
	

	using namespace std;

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
			shared_ptr<Fen> fen;
		public:
			MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare);
			~MoveGenerationController();
			uint32_t getBestMove(int depth);
			int alphaBeta(int alpha, int beta, int depthRemaining);
			void generateMovesAt(int from);
			void generateAllMoves();
			int maximizeFor = WHITE;
	};
#endif