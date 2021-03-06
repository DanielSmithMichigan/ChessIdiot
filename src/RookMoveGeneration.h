#ifndef RookMoveGeneration_h
#define RookMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateRookMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateRookMoves() {
		uint64_t rooks = Board::pieces[ROOK] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);
		while(rooks) {
			uint32_t rookLocation = popBit(rooks);
			uint64_t allRookMoves = BitBoard::getRookMoves<COLOR>(rookLocation, Board::occupiedSquares, Board::colors[COLOR]);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allRookMoves;
			while(captureMoves) {
				uint32_t captureMove = popBit(captureMoves);
				MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, rookLocation, captureMove);
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allRookMoves;
				while(nonCaptureMoves) {
					uint32_t nonCaptureMove = popBit(nonCaptureMoves);
					MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, rookLocation, nonCaptureMove);
				}
			}
		}
	}
#endif