#ifndef Board_h
#define Board_h
	#include "Globals.h"
	#include "State.h"
	#include "Move.h"
	#include "Utility.h"
	#include "Zobrist.h"
	#include "PiecesValue.h"
	#include "BitBoard.h"
	#include "Lsb.h"
	#include <stdint.h>
	#include <iostream>
	
	#define MAX_MOVES_PLAYED 128

	using namespace std;

	class Board {
		private:
		protected:
		public:
			Board();
			~Board();
			static State* currentState;
			static int pieceValue;
			static void reset();
			static void doMove(uint32_t move);
			static void undoMove();
			static void getPinnedPieces();
			static uint32_t turn;
			static void put(uint32_t color, uint32_t piece, uint32_t location);
			static void remove(uint32_t color, uint32_t piece, uint32_t location);
			static uint32_t getPiece(uint32_t location);
			static uint32_t getColor(uint32_t location);
			static uint64_t occupiedSquares;
			static uint64_t colors[3];
			static uint64_t pieces[8];
			static uint32_t piecesIndex[64];
			static uint32_t colorsIndex[64];
			static int PiecesValue[7];
			static inline void decreaseStateDepth() {
				State *prevState = currentState->prev;
				delete currentState;
				currentState = prevState;
			}
			static inline void increaseStateDepth() {
				State* nextState = new State();
				nextState->prev = currentState;
				nextState->castlingRights = currentState->castlingRights;
				nextState->zobrist = currentState->zobrist;
				nextState->halfMoveCount = currentState->halfMoveCount + 1;
				if (currentState->enPassantTarget != NO_EN_PASSANT) {
					nextState->zobrist ^= Zobrist::EnPassant[GET_COLUMN(currentState->enPassantTarget)];
				}
				nextState->enPassantTarget = NO_EN_PASSANT;
				nextState->depth = currentState->depth + 1;
				currentState = nextState;
			}

			template<uint32_t COLOR, PieceType PIECE_TYPE>
			static inline uint64_t getPinnedPieces() {
				uint64_t pinned = 0;
				uint64_t kingBoard = pieces[KING] & colors[COLOR];
				uint32_t kingLocation = popBit(kingBoard);
				uint64_t opposingPieces = colors[OPPOSING_COLOR(COLOR)];
				uint64_t opposingRooks = pieces[ROOK] & opposingPieces;
				uint64_t opposingBishops = pieces[BISHOP] & opposingPieces;
				uint64_t opposingQueens = pieces[QUEEN] & opposingPieces;
				uint64_t attacks, firstXRay;
				if (PIECE_TYPE == BISHOP) {
					attacks = BitBoard::getBishopMovesWithoutCollision(kingLocation, Board::occupiedSquares);
				} else if (PIECE_TYPE == ROOK) {
					attacks = BitBoard::getRookMovesWithoutCollision(kingLocation, Board::occupiedSquares);
				}
				uint64_t firstBlockers = attacks & occupiedSquares;
				uint64_t occupiedWithoutFirstBlockers = occupiedSquares ^ firstBlockers;
				if (PIECE_TYPE == BISHOP) {
					firstXRay = BitBoard::getBishopMovesWithoutCollision(kingLocation, occupiedWithoutFirstBlockers);
				} else if (PIECE_TYPE == ROOK) {
					firstXRay = BitBoard::getRookMovesWithoutCollision(kingLocation, occupiedWithoutFirstBlockers);
				}
				uint64_t snipers = firstXRay & occupiedWithoutFirstBlockers;
				if (PIECE_TYPE == BISHOP) {
					snipers &= (opposingQueens | opposingBishops);
				} else if (PIECE_TYPE == ROOK) {
					snipers &= (opposingQueens | opposingRooks);
				}
				while(snipers) {
					uint32_t sniper = popBit(snipers);
					uint64_t line = BitBoard::betweenLines[sniper][kingLocation];
					pinned |= line & firstBlockers & colors[COLOR];
				}
				return pinned;
			}
	};
#endif