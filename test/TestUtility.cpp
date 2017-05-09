#include "TestUtility.h"
void assertMoveExists(string fenString) {
	bool found = false;
	Fen* fen = new Fen();
	MoveGenerationController::generateAllMoves();
	vector<string> fensFound;
	while (uint32_t currentMove = MoveStack::pop()) {
		Board::doMove(currentMove);
		string newFen = fen->getBoardSquares();
		fensFound.push_back(newFen);
		if (newFen.compare(fenString) == 0) {
			found = true;
		}
		Board::undoMove();
	}
	ASSERT_TRUE(found) << fenString << " should be an available move."
	  << " Moves found: " << endl
	  << boost::algorithm::join(fensFound, "\n");
}
void assertNotMoveExists(string fenString) {
	bool found = false;
	Fen* fen = new Fen();
	MoveGenerationController::generateAllMoves();
	while (uint32_t currentMove = MoveStack::pop()) {
		Board::doMove(currentMove);
		if (fen->getBoardSquares().compare(fenString) == 0) {
			found = true;
		}
		Board::undoMove();
	}
	ASSERT_FALSE(found) << fenString << " should not be an available move.";
}
void showAllMoves() {
	Fen* fen = new Fen();
	MoveGenerationController::generateAllMoves();
	while (uint32_t currentMove = MoveStack::pop()) {
		Board::doMove(currentMove);
		cout << fen->getBoardSquares() << endl;
		Board::undoMove();
	}
}
void assertMoveCount(int assertedAmount) {
	int moveCount = 0;
	Fen* fen = new Fen();
	MoveGenerationController::generateAllMoves();
	while (uint32_t currentMove = MoveStack::pop()) {
		moveCount++;
	}
	ASSERT_EQ(moveCount, assertedAmount) << "Should have generated the expected number of moves" << endl;
}
uint64_t bitBoardFromRows(uint64_t row1, uint64_t row2, uint64_t row3, uint64_t row4, uint64_t row5, uint64_t row6, uint64_t row7, uint64_t row8) {
	return binToDec(row8)
		| binToDec(row7) << rows<1>()
		| binToDec(row6) << rows<2>()
		| binToDec(row5) << rows<3>()
		| binToDec(row4) << rows<4>()
		| binToDec(row3) << rows<5>()
		| binToDec(row2) << rows<6>()
		| binToDec(row1) << rows<7>();
}
uint64_t binToDec(uint64_t row) {
	uint64_t output = 0;
	uint64_t mult = 0;
	while (row) {
		if (row & 1) {
			output += pow(2, mult);
		}	
		mult++;
		row /= 10;
	}
	return output;
}