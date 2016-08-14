#ifndef QueenMoveGenerator_h
#define QueenMoveGenerator_h
	#include "PieceMoveGenerator.h"

	using namespace std;

	class QueenMoveGenerator : public PieceMoveGenerator{
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
			QueenMoveGenerator(shared_ptr<Board> board);
			~QueenMoveGenerator();
	};
#endif