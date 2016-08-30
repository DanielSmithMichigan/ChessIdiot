#ifndef QueenMoveGenerator_h
#define QueenMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class QueenMoveGenerator : public SlideMoveGenerator{
		private:
			bool canSlideEast = true;
			bool canSlideNorthEast = true;
			bool canSlideNorth = true;
			bool canSlideNorthWest = true;
			bool canSlideWest = true;
			bool canSlideSouthWest = true;
			bool canSlideSouth = true;
			bool canSlideSouthEast = true;
		public:
			QueenMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~QueenMoveGenerator();
	};
#endif