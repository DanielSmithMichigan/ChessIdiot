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
			static void augmentCurrentState();
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

			template<uint32_t COLOR, PieceType PIECE_UNDER_ATTACK, PieceType ATTACK_TYPE>
			static inline void getPinnedPieces(uint64_t &pinned, uint64_t &firstXRayAttacks) {
				uint64_t attackedPieceBoard = pieces[PIECE_UNDER_ATTACK] & colors[COLOR];
				while(attackedPieceBoard) {
					uint32_t pieceLocation = popBit(attackedPieceBoard);
					uint64_t opposingPieces = colors[OPPOSING_COLOR(COLOR)];
					uint64_t opposingRooks = pieces[ROOK] & opposingPieces;
					uint64_t opposingBishops = pieces[BISHOP] & opposingPieces;
					uint64_t opposingQueens = pieces[QUEEN] & opposingPieces;
					uint64_t attacks, firstXRay;
					if (ATTACK_TYPE == BISHOP) {
						attacks = BitBoard::getBishopMovesWithoutCollision(pieceLocation, Board::occupiedSquares);
					} else if (ATTACK_TYPE == ROOK) {
						attacks = BitBoard::getRookMovesWithoutCollision(pieceLocation, Board::occupiedSquares);
					}
					uint64_t firstBlockers = attacks & occupiedSquares;
					uint64_t occupiedWithoutFirstBlockers = occupiedSquares ^ firstBlockers;
					if (ATTACK_TYPE == BISHOP) {
						firstXRay = BitBoard::getBishopMovesWithoutCollision(pieceLocation, occupiedWithoutFirstBlockers);
					} else if (ATTACK_TYPE == ROOK) {
						firstXRay = BitBoard::getRookMovesWithoutCollision(pieceLocation, occupiedWithoutFirstBlockers);
					}
					uint64_t snipers = firstXRay & occupiedWithoutFirstBlockers;
					if (ATTACK_TYPE == BISHOP) {
						snipers &= (opposingQueens | opposingBishops);
					} else if (ATTACK_TYPE == ROOK) {
						snipers &= (opposingQueens | opposingRooks);
					}
					while(snipers) {
						uint32_t sniper = popBit(snipers);
						uint64_t line = BitBoard::betweenLines[sniper][pieceLocation];
						uint64_t pinnedPieces = line & firstBlockers & colors[COLOR];
						if (pinnedPieces) {
							pinned |= pinnedPieces;
							firstXRayAttacks |= getPieceBoard(sniper);
						}
					}
				}
			}

			template<uint32_t COLOR, PieceType PIECE_UNDER_ATTACK>
			static inline void getAttackers(uint64_t &attackedPieces, uint64_t &attackers, uint64_t &blockingSquares) {
				uint64_t attackedPiecesBoard = pieces[PIECE_UNDER_ATTACK] & colors[COLOR];
				while(attackedPiecesBoard) {
					uint64_t currentAttackers = 0;
					uint32_t pieceLocation = popBit(attackedPiecesBoard);
					uint32_t attackedPieceBoard = getPieceBoard(pieceLocation);
					uint64_t opposingPieces = colors[OPPOSING_COLOR(COLOR)];
					uint64_t opposingRooks = pieces[ROOK] & opposingPieces;
					uint64_t opposingBishops = pieces[BISHOP] & opposingPieces;
					uint64_t opposingQueens = pieces[QUEEN] & opposingPieces;
					uint64_t attackingBishops = BitBoard::getBishopMovesWithoutCollision(pieceLocation, Board::occupiedSquares) & (opposingBishops | opposingQueens);
					uint64_t attackingRooks = BitBoard::getRookMovesWithoutCollision(pieceLocation, Board::occupiedSquares) & (opposingRooks | opposingQueens);
					uint64_t slideAttackers = attackingBishops | attackingRooks;
					while(slideAttackers) {
						uint32_t slideAttacker = popBit(slideAttackers);
						currentAttackers |= slideAttacker;
						blockingSquares |= BitBoard::betweenLines[slideAttacker][pieceLocation];
					}

					uint64_t opposingPawns = pieces[PAWN] & colors[OPPOSING_COLOR(COLOR)];
					uint64_t pawnAttackSquareLeft = attackedPieceBoard;
					uint64_t pawnAttackSquareRight = attackedPieceBoard;
					shiftPawns<LEFT>(pawnAttackSquareLeft);
					shiftPawns<RIGHT>(pawnAttackSquareRight);
					uint64_t pawnAttackSquares = pawnAttackSquareLeft | pawnAttackSquareRight;
					pushPawns<COLOR, 1>(pawnAttackSquares);
					uint64_t attackingPawns = pawnAttackSquares & opposingPawns;
					currentAttackers |= attackingPawns;
					blockingSquares |= attackingPawns;

					uint64_t opposingKnights = pieces[KNIGHT] & colors[OPPOSING_COLOR(COLOR)];
					uint64_t attackingKnightSquares = BitBoard::getKnightMoves<OPPOSING_COLOR(COLOR)>(attackedPieceBoard, 0);
					uint64_t attackingKnights = opposingKnights & attackingKnightSquares;
					currentAttackers |= attackingKnights;
					blockingSquares |= attackingKnights;
					if (currentAttackers) {
						attackedPieces |= attackedPieceBoard;
						attackers |= currentAttackers;
					}
				}
			}
	};
#endif