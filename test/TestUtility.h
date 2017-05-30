#ifndef TestUtility_h
#define TestUtility_h
	#include <boost/algorithm/string/join.hpp>
	#include "../src/MoveGenerationController.h"
	#include "../src/MoveStack.h"
	#include "../src/Fen.h"
	#include "gtest/gtest.h"
	#include "gmock/gmock.h"
	#include <stdint.h>
	void assertMoveExists(string fenString, string param = "");
	void assertNotMoveExists(string fenString,  string param = "");
	void showAllMoves();
	void assertMoveCount(int assertedAmount);
#endif