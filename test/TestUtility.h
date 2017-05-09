#ifndef TestUtility_h
#define TestUtility_h
	#include <boost/algorithm/string/join.hpp>
	#include "../src/MoveGenerationController.h"
	#include "../src/MoveStack.h"
	#include "../src/Fen.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <stdint.h>
	#include <math.h>
	void assertMoveExists(string fenString);
	void assertNotMoveExists(string fenString);
	void showAllMoves();
	void assertMoveCount(int assertedAmount);
	uint64_t bitBoardFromRows(uint64_t row1, uint64_t row2, uint64_t row3, uint64_t row4, uint64_t row5, uint64_t row6, uint64_t row7, uint64_t row8);
	uint64_t binToDec(uint64_t row);
#endif