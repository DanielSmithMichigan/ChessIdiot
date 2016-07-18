#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "MoveGenerator.h"
	#include <cmath>

	using namespace std;

	class KnightMoveGenerator : public MoveGenerator{
		private:
			uint64_t generateKnightMovesAtLocation(int x, int y);
			bool onBoard(int x, int y);
			bool isValidKnightMove(int x, int y);
		public:
			void generatePotentialMoveSets();
			KnightMoveGenerator();
			~KnightMoveGenerator();
	};
#endif