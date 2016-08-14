#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "PieceMoveGenerator.h"
	#include <cmath>

	using namespace std;

	class KnightMoveGenerator : public PieceMoveGenerator{
		private:
			bool canMoveAsKnight = true;
		public:
			KnightMoveGenerator();
			~KnightMoveGenerator();
	};
#endif