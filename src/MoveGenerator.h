#ifndef MoveGenerator_h
#define MoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include <list>
	#include <vector>
	#include "utilities.h"
	#include "globals.h"
	#include "MoveStack.h"
	#include "Move.h"
	#include "Board.h"

	using namespace std;

	class MoveGenerator {
		private:
		protected:
			shared_ptr<Board> board;
			shared_ptr<MoveStack> moveStack;
		public:
			MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack>);
			~MoveGenerator();
			void generateMoves(int location);
			void generateSlideMove(int from, int delta);
			void generateMove(int from, int to);
	};
#endif