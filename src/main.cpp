#include <iostream>
#include "Board.h"
#include "TerminalDisplay.h"
#include "UbuntuScreen.h"
#include "UserCommand.h"
#include "Game.h"
#include <ncurses.h>
using namespace std;

int main(int argc, char** argv )
{
    shared_ptr<Board> board(new Board());
	unique_ptr<TerminalDisplay> terminalDisplay (new TerminalDisplay(board));
	unique_ptr<Game> game(new Game(board, new UserCommand()));
	terminalDisplay->draw();
    return 0;
}