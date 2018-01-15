#include "src/Uci.h"
#include "src/ConstructUci.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv)
{
	ConstructUci::instance->fromArgv(argc, argv);
	// Uci::instance->loop();
	// Search::instance->iterativeDeepening("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1", 99);
	// Fen::import("r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1");
	// MoveGenerationController::instance->getBestMove(7);
    return 0;
}