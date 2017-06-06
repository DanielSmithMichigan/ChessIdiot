#include "src/BitBoard.h"
#include "src/Search.h"
#include "src/TranspositionTable.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv )
{
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();
	TranspositionTable::instance->reset();
	Search::instance->iterativeDeepening("r4rk1/ppp1bppp/3p1n2/4n3/3NP3/1BN4q/PPP2P2/R1BQR1K1 w - - 12 8", 99);
	// Fen::import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1");
	// MoveGenerationController::instance->getBestMove(7);
    return 0;
}