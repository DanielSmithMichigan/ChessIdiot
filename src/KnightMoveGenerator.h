#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "MoveGenerator.h"
	#include "utilities.h"

	using namespace std;

	class KnightMoveGenerator : public MoveGenerator{
		private:
		public:
			KnightMoveGenerator(shared_ptr<Board> board);
			~KnightMoveGenerator();
			uint64_t movesAt(int x, int y, int color);
	};
#endif