#ifndef MoveGenerator_h
#define MoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include "utilities.h"
	#include "globals.h"

	using namespace std;

	class MoveGenerator {
		private:
		public:
			bool canMoveNorth = false;
			bool canMoveEast = false;
			bool canMoveSouth = false;
			bool canMoveWest = false;
			uint64_t potentialMoveSets[8][8];
			void generatePotentialMoveSets();
			uint64_t generateEastMoves(int x, int y);
			uint64_t generateWestMoves(int x, int y);
			uint64_t generateNorthMoves(int x, int y);
			uint64_t generateSouthMoves(int x, int y);
			uint64_t movesAt(int x, int y);
			MoveGenerator();
			~MoveGenerator();
	};
#endif