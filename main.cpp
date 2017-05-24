#include "src/BitBoard.h"
#include "src/Fen.h"
#include "src/MoveGenerationController.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv )
{
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();
	MoveStack::reset();
	Fen::import("2r2rk1/pb1qbppp/1p2p3/2pnP3/8/1PN1PB2/PB3PPP/2RQ1RK1 w KQkq -"); // benchmark
	uint32_t bestMove = MoveGenerationController::getBestMove(5);
	cout << "FROM: " << FROM(bestMove)
	     << " TO: " << TO(bestMove) << endl;
    return 0;
}