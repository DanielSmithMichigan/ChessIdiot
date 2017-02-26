#ifndef BoardValue_h
#define BoardValue_h
	#include "Board.h"
	#include "AttackedSquare.h"
	
	#define MAX_MOVES_PLAYED 128

	using namespace std;

	class BoardValue {
		private:
			shared_ptr<Board> board;
			shared_ptr<AttackedSquare> attackedSquare;
		public:
			BoardValue(shared_ptr<Board> board, shared_ptr<AttackedSquare> attackedSquare);
			~BoardValue();
			int get(bool legalMovesExist);
			int sumOfPieces();
	};
#endif