#ifndef BishopMoveGenerator_h
#define BishopMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class BishopMoveGenerator : public SlideMoveGenerator{
		private:
			bool canSlideEast = false;
			bool canSlideNorthEast = true;
			bool canSlideNorth = false;
			bool canSlideNorthWest = true;
			bool canSlideWest = false;
			bool canSlideSouthWest = true;
			bool canSlideSouth = false;
			bool canSlideSouthEast = true;
		public:
			BishopMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~BishopMoveGenerator();
	};
#endif