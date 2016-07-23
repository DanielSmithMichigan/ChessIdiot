#ifndef PieceMoveGenerator_h
#define PieceMoveGenerator_h
	#include <stdint.h>
	#include <iostream>
	#include "utilities.h"
	#include "globals.h"

	using namespace std;

	class PieceMoveGenerator {
		private:
		public:
			bool canSlideNorth = false;
			bool canSlideNorthEast = false;
			bool canSlideEast = false;
			bool canSlideSouthEast = false;
			bool canSlideSouth = false;
			bool canSlideSouthWest = false;
			bool canSlideWest = false;
			bool canSlideNorthWest = false;
			uint64_t potentialMoveSets[8][8];
			void generatePotentialMoveSets();
			uint64_t generateNorthSlide(int x, int y);
			uint64_t generateNorthEastSlide(int x, int y);
			uint64_t generateEastSlide(int x, int y);
			uint64_t generateSouthEastSlide(int x, int y);
			uint64_t generateSouthSlide(int x, int y);
			uint64_t generateSouthWestSlide(int x, int y);
			uint64_t generateWestSlide(int x, int y);
			uint64_t generateNorthWestSlide(int x, int y);
			uint64_t movesAt(int x, int y);
			PieceMoveGenerator();
			~PieceMoveGenerator();
	};
#endif