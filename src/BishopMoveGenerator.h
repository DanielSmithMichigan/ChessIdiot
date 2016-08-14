#ifndef BishopMoveGenerator_h
#define BishopMoveGenerator_h
	#include "PieceMoveGenerator.h"

	using namespace std;

	class BishopMoveGenerator : public PieceMoveGenerator{
		private:
			bool canSlideNorthEast = true;
			bool canSlideNorthWest = true;
			bool canSlideSouthWest = true;
			bool canSlideSouthEast = true;
		public:
			BishopMoveGenerator(shared_ptr<Board> board);
			~BishopMoveGenerator();
	};
#endif