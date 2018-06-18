#ifndef QueenMoveGeneration_h
#define QueenMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateQueenMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateQueenMoves() {
		uint64_t queens = Board::pieces[QUEEN] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);
		while(queens) {
			uint32_t queenLocation = popBit(queens);
			uint64_t allQueenMoves = BitBoard::getBishopMoves<COLOR>(queenLocation, Board::occupiedSquares, Board::colors[COLOR]) | BitBoard::getRookMoves<COLOR>(queenLocation, Board::occupiedSquares, Board::colors[COLOR]);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allQueenMoves;
			while(captureMoves) {
				uint32_t captureMove = popBit(captureMoves);
				MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, queenLocation, captureMove);
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allQueenMoves;
				while(nonCaptureMoves) {
					uint32_t nonCaptureMove = popBit(nonCaptureMoves);
					MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, queenLocation, nonCaptureMove);
				}
			}
		}
	}
#endif