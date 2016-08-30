#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h
	#include "MoveGenerator.h"

	using namespace std;

	class PawnMoveGenerator : public MoveGenerator{
		private:
			int knightMoves[8] = {ROWS(2) + 1, ROWS(2) - 1, ROWS(1) + 2, ROWS(1) - 2, ROWS(-1) + 2, ROWS(-1) - 2, ROWS(-2) + 1, ROWS(-2) - 1};
		public:
			PawnMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~PawnMoveGenerator();
			void generateMoves(int from);
	};
#endif