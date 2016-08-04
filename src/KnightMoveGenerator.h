#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "PieceMoveGenerator.h"
	#include <cmath>

	using namespace std;

	class KnightMoveGenerator : public PieceMoveGenerator{
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