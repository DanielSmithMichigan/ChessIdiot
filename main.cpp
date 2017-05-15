#include "src/BitBoard.h"
#include <stdlib.h>

using namespace std;
int main(int argc, char** argv )
{
	BitBoard::InitRookBitBoards();
	BitBoard::InitBishopBitBoards();

	int testValues[] = {
		-1, 0, 1
	};

	int counter = 0;

	for (int y = 0; y < ROW; y++) {
		for (int x = 0; x < ROW; x++) {
			uint64_t board = 0;
			for (int xMod = 0; xMod < 3; xMod++) {
				for (int yMod = 0; yMod < 3; yMod++) {
					if (testValues[xMod] == 0
						&& testValues[yMod] == 0) {
						continue;
					}
					int newX = x + testValues[xMod];
					int newY = y + testValues[yMod];
					if (newX >= 0 
						&& newX <=7
						&& newY >= 0
						&& newY <= 7) {
						board |= getPieceBoard(newX, newY);
					}
				}
			}
			counter++;
			cout << "COUNTER: " << counter << " BOARD: " << board << endl;
			// showBitBoard(board);
		}
	}
    return 0;
}