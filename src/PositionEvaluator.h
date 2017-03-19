#ifndef BoardValue_h
#define BoardValue_h
	#include "Board.h"
	#include "AttackedSquare.h"
	
	#define MAX_MOVES_PLAYED 128

	using namespace std;

	class PositionEvaluator {
		private:
			shared_ptr<Board> board;
			shared_ptr<AttackedSquare> attackedSquare;
		public:
			PositionEvaluator(shared_ptr<Board> board, shared_ptr<AttackedSquare> attackedSquare);
			~PositionEvaluator();
			int terminalPositionValue();
			int piecesValue();
	};
#endif