#include "src/BitBoard.h"

using namespace std;

uint64_t random64() {
	uint64_t u1, u2, u3, u4;
	u1 = (uint64_t)(rand()) & 0xFFFF; u2 = (uint64_t)(rand()) & 0xFFFF;
	u3 = (uint64_t)(rand()) & 0xFFFF; u4 = (uint64_t)(rand()) & 0xFFFF;
	return u1 | (u2 << 16) | (u3 << 32) | (u4 << 48);
}

uint64_t getTestMagic(uint64_t occupancyMask) {
	uint64_t testMagic;
	do {
		testMagic = random64() & random64() & random64();
	} while(countOnes((occupancyMask * testMagic) & 0xFF00000000000000ULL) < 6);
	return testMagic;
}


bool valid(uint64_t testMagic, uint64_t occupancyMask) {
	bool used[4096] = {false};
	uint64_t subset = 0;
	uint64_t index;
	uint64_t shift = 64 - countOnes(occupancyMask);
	do {
		subset = (subset - occupancyMask) & occupancyMask;
		index = (subset * testMagic) >> shift;
		if (!used[index]) {
			used[index] = true;
		} else {
			return false;
		}
	} while (subset);
	return true;
}

uint64_t getRookMask(int location) {
	return (generateSlideMove(0, location, 0, -1) & ~row<0>())
				| (generateSlideMove(0, location, 1, 0) & ~file<7>())
				| (generateSlideMove(0, location, 0, 1) & ~row<7>())
				| (generateSlideMove(0, location, -1, 0) & ~file<0>());
}

uint64_t getBishopmask(int location) {
	return (generateSlideMove(0, location, -1, -1) & ~row<0>() & ~file<0>())
		| (generateSlideMove(0, location, 1, -1) & ~row<0>() & ~file<7>())
		| (generateSlideMove(0, location, 1, 1) & ~row<7>() & ~file<7>())
		| (generateSlideMove(0, location, -1, 1) & ~row<7>() & ~file<0>());
}

uint64_t findMagic(int location) {
	uint64_t occupancyMask = getBishopmask(location);
	uint64_t testMagic;
	do {
		testMagic = getTestMagic(occupancyMask);
	} while(!valid(testMagic, occupancyMask));
	cout << testMagic << endl;
}

int main(int argc, char** argv )
{
	// shared_ptr<Board> board(new Board());
	// shared_ptr<MoveStack> moveStack(new MoveStack(board));
	// shared_ptr<AttackedSquare> attackedSquare(new AttackedSquare(board));
	// shared_ptr<Fen> fen(new Fen(board));
	// shared_ptr<MoveGenerationController> moveGenerationController(new MoveGenerationController(board, moveStack, attackedSquare));
	// fen->import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1"); // benchmark
	// fen->import("r4n2/2r3kp/5n1R/p1Np2p1/1p1P2q1/4PQ2/PP1NK3/7R w - - 0 1");
	// int bestMove = moveGenerationController->getBestMove(5);
	// cout << "FROM: " << FROM(bestMove)
	//      << " TO: " << TO(bestMove)
	//      << endl;
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();

	int square = 0;
	uint64_t occupancyBoard = bitBoardFromRows(
		00000000,
		00000000,
		10000000,
		10010000,
		10001000,
		10000000,
		00000000,
		00000000
	);
	uint64_t occupancyMask = BitBoard::BishopOccupancyMasks[square] & occupancyBoard;
	showBitBoard(
		BitBoard::BishopPointers[square][(occupancyMask * BitBoard::BishopMagics[square]) >> BitBoard::BishopShifts[square]]
	);
    return 0;
}