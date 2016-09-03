#ifndef BishopMoveGenerator_h
#define BishopMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class BishopMoveGenerator : public SlideMoveGenerator{
		public:
			BishopMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~BishopMoveGenerator();
	};
#endif