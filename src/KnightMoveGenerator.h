#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "PieceMoveGenerator.h"
	#include "utilities.h"

	using namespace std;

	class KnightMoveGenerator : public PieceMoveGenerator{
		private:
		public:
			KnightMoveGenerator(shared_ptr<Board> board);
			~KnightMoveGenerator();
			uint64_t movesAt(int x, int y, uint64_t color);
	};
#endif