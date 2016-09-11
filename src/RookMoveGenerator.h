#ifndef RookMoveGenerator_h
#define RookMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class RookMoveGenerator : public SlideMoveGenerator{
		public:
			RookMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare);
			~RookMoveGenerator();
	};
#endif