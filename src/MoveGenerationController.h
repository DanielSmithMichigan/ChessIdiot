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
	

	using namespace std;

	class MoveGenerationController {
		private:
			shared_ptr<Board> board;
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
			void generateMovesAt(int from);
	};
#endif