#include "test/KingMoveGenerator.h"
using namespace std;

int main(int argc, char** argv )
{
	shared_ptr<KingMoveGeneratorTest> kingMoveGeneratorTest(new KingMoveGeneratorTest());
	kingMoveGeneratorTest->run();
    return 0;
}