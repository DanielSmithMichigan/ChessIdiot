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
			uint8_t potentialMoveSets[64];
			void generatePotentialMoveSets();
			uint8_t generateEastMoves(int x, int y);
			uint8_t generateWestMoves(int x, int y);
			uint8_t generateNorthMoves(int x, int y);
			uint8_t generateSouthMoves(int x, int y);
			MoveGenerator();
			~MoveGenerator();
	};
#endif