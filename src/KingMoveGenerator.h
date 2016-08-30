#ifndef KingMoveGenerator_h
#define KingMoveGenerator_h
	#include "MoveGenerator.h"
	#define KING_MOVES_SIZE 8

	using namespace std;

	class KingMoveGenerator : public MoveGenerator{
		private:
			int kingMoves[8] = {ROWS(1), ROWS(1) + 1, 1, ROWS(-1) + 1, ROWS(-1), ROWS(-1) - 1, -1, ROWS(1) - 1};
		public:
			KingMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~KingMoveGenerator();
			void generateMoves(int from);
	};
#endif