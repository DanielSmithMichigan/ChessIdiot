#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	MoveGenerator::MoveGenerator(shared_ptr<Board> board) :
	board(move(board)) {
		moveCache.reset(new MoveCache());
	}

	MoveGenerator::~MoveGenerator() {

	}

	uint64_t MoveGenerator::generateSlideMoves(int x, int y, int direction) {
		uint64_t moveBoard = moveCache->moveBoards[x][y][direction];
		int color = board->squares[x][y]->color;
		if ((board->occupiedSpace & moveBoard) == 0) {
			return moveBoard;
		}

		bool endOnNext = false;
		for (list<Move>::iterator i = moveCache->moveLists[x][y][direction].begin(); i != moveCache->moveLists[x][y][direction].end(); i++) {
			if (endOnNext || board->squares[(*i).x2][(*i).y2]->piece != EMPTY_SPACE) {
				if (endOnNext || board->squares[(*i).x2][(*i).y2]->color == board->squares[x][y]->color) {
					moveBoard &= ~moveCache->moveBoards[(*i).x2][(*i).y2][direction];
					return moveBoard;
				} else {
					endOnNext = true;
				}
			}
		}
		return moveBoard;
	}
#endif