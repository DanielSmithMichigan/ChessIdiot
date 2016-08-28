#ifndef MoveCache_h
#define MoveCache_h
	#include <stdint.h>
	#include <iostream>
	#include <list>
	#include <vector>
	#include "utilities.h"
	#include "globals.h"
	#include "Move.h"

	using namespace std;

	class MoveCache {
		private:
		protected:
		public:
			uint64_t moveBoards[8][8][13];
			uint32_t moves[8][8][13][8];
			void generate();
			void generateBoards(int x, int y);
			void generateLists(int x, int y);
			uint64_t generateBoardFromList(int x, int y, int moveType);
			void generateSlideList(int x, int y, int eastWest, int northSouth, int moveListIndex);
			void generateKnightList(int x, int y);
			void generatePawnAttackList(int x, int y, int color);
			void generatePawnForwardList(int x, int y, int color);
			bool isValidKnightMove(int x, int y);
			bool onBoard(int x, int y);
			int getXModifier(int eastWest);
			int getYModifier(int northSouth);
			MoveCache();
			~MoveCache();
	};
#endif