#ifndef RookMoveGenerator_h
#define RookMoveGenerator_h
	#include "SlideMoveGenerator.h"

	using namespace std;

	class RookMoveGenerator : public SlideMoveGenerator{
		private:
			bool canSlideEast = true;
			bool canSlideNorthEast = false;
			bool canSlideNorth = true;
			bool canSlideNorthWest = false;
			bool canSlideWest = true;
			bool canSlideSouthWest = false;
			bool canSlideSouth = true;
			bool canSlideSouthEast = false;
		public:
			RookMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~RookMoveGenerator();
	};
#endif