#ifndef MoveGenerator_h
#define MoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include <list>
	#include <vector>
	#include "utilities.h"
	#include "globals.h"
	#include "Move.h"
	#include "Board.h"
	#include "MoveCache.h"

	using namespace std;

	class MoveGenerator {
		private:
		protected:
			shared_ptr<Board> board;
			unique_ptr<MoveCache> moveCache;
			vector<vector<vector<uint64_t>>> moveBoards;
			vector<vector<vector<list<Move>>>> moveLists;
		public:
			MoveGenerator(shared_ptr<Board> board);
			~MoveGenerator();
			uint64_t generateSlideMoves(int x, int y, int direction);
	};
#endif