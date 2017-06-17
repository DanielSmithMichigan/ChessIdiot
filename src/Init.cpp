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
		TranspositionTable::instance->reset();
		Board::clearForSearch();
		Search::instance->clearForSearch();
		finished = true;
	}

	void Init::reset() {
		Board::clearForSearch();
		Search::instance->clearForSearch();
	}
#endif