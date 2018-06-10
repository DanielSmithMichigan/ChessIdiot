#ifndef BishopMoveGeneration_h
#define BishopMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Fen.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateBishopMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateBishopMoves() {
		uint64_t bishops = Board::pieces[BISHOP] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);
		while(bishops) {
			uint32_t bishopLocation = popBit(bishops);
			uint64_t bishopBoard = getPieceBoard(bishopLocation);
			uint64_t pinned = bishopBoard & Board::currentState->pinnedToKing[COLOR];
			uint64_t allBishopMoves = BitBoard::getBishopMoves<COLOR>(bishopLocation, Board::occupiedSquares, Board::colors[COLOR]);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allBishopMoves;
			while(captureMoves) {
				uint32_t captureMove = popBit(captureMoves);
				if (pinned
					&& !BitBoard::aligned(kingLocation, captureMove, bishopBoard)) {
					continue;
				} 
				MoveStack::instance->push(quietMove(bishopLocation, captureMove));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allBishopMoves;
				while(nonCaptureMoves) {
					uint32_t nonCaptureMove = popBit(nonCaptureMoves);
					if (pinned
						&& !BitBoard::aligned(kingLocation, nonCaptureMove, bishopBoard)) {
						continue;
					} 
					MoveStack::instance->push(quietMove(bishopLocation, nonCaptureMove));
				}
			}
		}
	}
#endif