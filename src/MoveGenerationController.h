#ifndef MoveGenerationController_h
#define MoveGenerationController_h
	#include "Board.h"
	#include "PawnMoveGeneration.h"
	

	using namespace std;

	class MoveGenerationController {
		private:
		public:
			MoveGenerationController();
			~MoveGenerationController();
			static void generateAllMoves();
	};
#endif