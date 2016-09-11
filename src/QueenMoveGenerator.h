#ifndef QueenMoveGenerator_h
#define QueenMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class QueenMoveGenerator : public SlideMoveGenerator{
		public:
			QueenMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare);
			~QueenMoveGenerator();
	};
#endif