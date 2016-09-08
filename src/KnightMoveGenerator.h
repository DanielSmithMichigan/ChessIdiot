#ifndef KnightMoveGenerator_h
#define KnightMoveGenerator_h
	#include "MoveGenerator.h"
	#define KNIGHT_MOVES_SIZE 8

	using namespace std;

	class KnightMoveGenerator : public MoveGenerator{
		private:
			int knightMoves[8] = {KNIGHT_MOVE_1, KNIGHT_MOVE_2, KNIGHT_MOVE_3, KNIGHT_MOVE_4, KNIGHT_MOVE_5, KNIGHT_MOVE_6, KNIGHT_MOVE_7, KNIGHT_MOVE_8};
		public:
			KnightMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack);
			~KnightMoveGenerator();
			void generateMoves(int from);
	};
#endif