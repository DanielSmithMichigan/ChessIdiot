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
			vector<unique_ptr<MoveGenerator>> moveGenerators;
		public:
			MoveGenerationController(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~MoveGenerationController();
	};
#endif