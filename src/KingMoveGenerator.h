#ifndef KingMoveGenerator_h
#define KingMoveGenerator_h
	#include "MoveGenerator.h"
	#define KING_MOVES_SIZE 8

	using namespace std;

	class KingMoveGenerator : public MoveGenerator{
		private:
			int kingMoves[8] = {KING_MOVE_1, KING_MOVE_2, KING_MOVE_3, KING_MOVE_4, KING_MOVE_5, KING_MOVE_6, KING_MOVE_7, KING_MOVE_8};
			int whiteCastleSquaresEast[2] = {117, 118};
			int whiteCastleSquaresWest[2] = {114, 115};
			int blackCastleSquaresEast[2] = {4, 5};
			int blackCastleSquaresWest[2] = {2, 3};
			int whiteCastleLeft = 112;
			int whiteCastleRight = 119;
			int blackCastleLeft = 0;
			int blackCastleRight = 7;
		public:
			KingMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare);
			~KingMoveGenerator();
			void generateMoves(int from);
			void generateAdjacentMoves(int from);
			void generateCastle(int from);
			bool castleSquaresOccupied(int from, int eastWest);
			bool castleSquaresAttacked(int from, int eastWest);
			int (&getArrayOfSquares(int from, int eastWest))[2];
	};
#endif