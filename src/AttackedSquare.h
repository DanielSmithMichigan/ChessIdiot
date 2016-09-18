#ifndef AttackedSquare_h
#define AttackedSquare_h
	#include "Board.h"

	using namespace std;

	class AttackedSquare {
		private:
			shared_ptr<Board> board;
			int knightMoves[8] = {KNIGHT_MOVE_1, KNIGHT_MOVE_2, KNIGHT_MOVE_3, KNIGHT_MOVE_4, KNIGHT_MOVE_5, KNIGHT_MOVE_6, KNIGHT_MOVE_7, KNIGHT_MOVE_8};
			int kingMoves[8] = {KING_MOVE_1, KING_MOVE_2, KING_MOVE_3, KING_MOVE_4, KING_MOVE_5, KING_MOVE_6, KING_MOVE_7, KING_MOVE_8};
		public:
			AttackedSquare(shared_ptr<Board> board);
			~AttackedSquare();
			bool check(int location, int attackedBy = BLANK);
			bool attackedByKnight(int location, int attackedBy = BLANK);
			bool attackedByKing(int location, int attackedBy = BLANK);
			bool attackedByPawn(int location, int attackedBy = BLANK);
			bool attackedBySlidingPiece(int from, int delta, int otherAttackingPiece, int attackedBy = BLANK);
			bool kingInCheck(int kingColor = BLANK);
			int defaultColor(int attackedBy);
	};
#endif