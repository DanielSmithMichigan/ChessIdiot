#ifndef Init_cpp
#define Init_cpp
	#include "Init.h"

	Init *Init::instance = new Init();


	Init::Init() {
		finished = false;
	}

	Init::~Init() {

	}

	void Init::execute(bool force) {
		if (finished && !force) {
			return;
		}
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		BitBoard::InitLines<ROOK>();
		BitBoard::InitLines<BISHOP>();
		TranspositionTable::instance->reset();
		Search::instance->clearForSearch();
		MoveStack::instance->reset();
		Zobrist::Init();
		finished = true;
	}

	void Init::reset() {
		Search::instance->clearForSearch();
	}
#endif