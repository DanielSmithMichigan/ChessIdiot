#include "src/BitBoard.h"
#include "src/Fen.h"
#include "src/MoveGenerationController.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv )
{
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();
	Fen::import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1"); // benchmark
	int bestMove = MoveGenerationController::getBestMove(5);
    return 0;
}