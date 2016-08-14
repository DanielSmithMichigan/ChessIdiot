#ifndef RookMoveGenerator_h
#define RookMoveGenerator_h
	#include "PieceMoveGenerator.h"

	using namespace std;

	class RookMoveGenerator : public PieceMoveGenerator{
		private:
			bool canSlideEast = true;
			bool canSlideNorth = true;
			bool canSlideWest = true;
			bool canSlideSouth = true;
		public:
			RookMoveGenerator(shared_ptr<Board> board);
			~RookMoveGenerator();
	};
#endif