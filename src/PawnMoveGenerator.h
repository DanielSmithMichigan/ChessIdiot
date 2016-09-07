#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h
	#include "MoveGenerator.h"

	using namespace std;

	class PawnMoveGenerator : public MoveGenerator{
		public:
			int direction = 1;
			PawnMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~PawnMoveGenerator();
			void generateMoves(int from);
			void testAndGenerateMove(int from, int to, int piece);
	};
#endif