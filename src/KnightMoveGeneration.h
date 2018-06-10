#ifndef KnightMoveGeneration_h
#define KnightMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateKnightMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateKnightMoves() {
		uint64_t knights = Board::pieces[KNIGHT] & Board::colors[COLOR];
		while(knights) {
			uint32_t knightLocation = popBit(knights);
			uint64_t knightBoard = getPieceBoard(knightLocation);
			uint64_t pinned = knightBoard & Board::currentState->pinnedToKing[COLOR];
			if (pinned) {
				continue;
			}
			uint64_t allKnightMoves = BitBoard::getKnightMoves<COLOR>(knightLocation, Board::colors[COLOR]);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allKnightMoves;
			while(captureMoves) {
				MoveStack::instance->push(quietMove(knightLocation, popBit(captureMoves)));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allKnightMoves;
				while(nonCaptureMoves) {
					MoveStack::instance->push(quietMove(knightLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}
#endif