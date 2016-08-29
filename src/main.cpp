#include <iostream>
#include "Board.h"
#include "TerminalDisplay.h"
#include "UbuntuScreen.h"
#include "SelectedSquare.h"
#include "Game.h"
#include "MoveStack.h"
#include <ncurses.h>
using namespace std;

int main(int argc, char** argv )
{
	shared_ptr<MoveStack> moveStack(new MoveStack());
    shared_ptr<Board> board(new Board());
	shared_ptr<TerminalDisplay> terminalDisplay (new TerminalDisplay(board));
	shared_ptr<SelectedSquare> selectedSquare(new SelectedSquare(board, terminalDisplay));
	unique_ptr<Game> game(new Game(board, selectedSquare, terminalDisplay));
	game->begin();
    return 0;
}