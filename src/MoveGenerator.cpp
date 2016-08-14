#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	MoveGenerator::MoveGenerator(shared_ptr<Board> board) : board(move(board)) {
		pieceMoveGenerators.resize(6);
		pieceMoveGenerators[ROOK].reset(new RookMoveGenerator(board));
		pieceMoveGenerators[KNIGHT].reset(new KnightMoveGenerator(board));
		pieceMoveGenerators[BISHOP].reset(new BishopMoveGenerator(board));
		pieceMoveGenerators[QUEEN].reset(new QueenMoveGenerator(board));
	}

	MoveGenerator::~MoveGenerator() {

	}

	uint64_t MoveGenerator::getMovesForPieceAt(int x, int y) {
		uint64_t piece = board->getPieceAtSquare(x, y);
		return pieceMoveGenerators[piece]->movesAt(x, y);
	}
#endif