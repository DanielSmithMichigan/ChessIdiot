#ifndef SlideMoveGenerator_h
#define SlideMoveGenerator_h
	#include "MoveGenerator.h"

	using namespace std;

	class SlideMoveGenerator : public MoveGenerator{
		private:
		protected:
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
		public:
			bool canMoveNorth = false;
			bool canMoveNorthEast = false;
			bool canMoveEast = false;
			bool canMoveSouthEast = false;
			bool canMoveSouth = false;
			bool canMoveSouthWest = false;
			bool canMoveWest = false;
			bool canMoveNorthWest = false;
			SlideMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack>);
			~SlideMoveGenerator();
			void generateMoves(int from);
			void generateSlideMove(int from, int delta);
	};
#endif