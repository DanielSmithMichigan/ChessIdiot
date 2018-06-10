#ifndef SquareAttacked_h
#define SquareAttacked_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	bool canTakeKing();
	bool kingInCheck();

	template <uint32_t COLOR> inline bool squareAttacked(uint32_t location);
	template <uint32_t COLOR>
	inline bool squareAttacked(uint32_t location) {
		uint64_t pieceBoard = getPieceBoard(location);
		uint64_t rooks = Board::pieces[ROOK] & Board::colors[COLOR];
		uint64_t bishops = Board::pieces[BISHOP] & Board::colors[COLOR];
		uint64_t queens = Board::pieces[QUEEN] & Board::colors[COLOR];
		uint64_t kings = Board::pieces[KING] & Board::colors[COLOR];
		uint64_t pawns = Board::pieces[PAWN] & Board::colors[COLOR];
		uint64_t knights = Board::pieces[KNIGHT] & Board::colors[COLOR];
		if (BitBoard::getBishopMoves<OPPOSING_COLOR(COLOR)>(location, Board::occupiedSquares, Board::colors[OPPOSING_COLOR(COLOR)])
			& (bishops | queens)) {
			return true;
		}
		if (BitBoard::getRookMoves<OPPOSING_COLOR(COLOR)>(location, Board::occupiedSquares, Board::colors[OPPOSING_COLOR(COLOR)])
			& (rooks | queens)) {
			return true;
		} 
		if (BitBoard::getKnightMoves<OPPOSING_COLOR(COLOR)>(location, Board::colors[OPPOSING_COLOR(COLOR)]) & knights) {
			return true;
		}
		if (BitBoard::getAdjacentKingMoves<OPPOSING_COLOR(COLOR)>(location, Board::colors[OPPOSING_COLOR(COLOR)]) & kings) {
			return true;
		}

		pushPawns<COLOR, 1>(pawns);
		uint64_t pawnsLeft = pawns, pawnsRight = pawns;
		shiftPawns<LEFT>(pawnsLeft);
		shiftPawns<RIGHT>(pawnsRight);
		if (pawnsLeft & pieceBoard) {
			return true;
		} else if (pawnsRight & pieceBoard) {
			return true;
		}

		return false;
	}
#endif