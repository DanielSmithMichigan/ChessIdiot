#ifndef KingMoveGenerator_h
#define KingMoveGenerator_h
	#include "MoveGenerator.h"
	#define KING_MOVES_SIZE 8

	using namespace std;

	class KingMoveGenerator : public MoveGenerator{
		private:
			int kingMoves[8] = {KING_MOVE_1, KING_MOVE_2, KING_MOVE_3, KING_MOVE_4, KING_MOVE_5, KING_MOVE_6, KING_MOVE_7, KING_MOVE_8};
		public:
			KingMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~KingMoveGenerator();
			void generateMoves(int from);
	};
#endif