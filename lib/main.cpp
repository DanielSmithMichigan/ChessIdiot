#include <iostream>
#include "Board.h"
#include "TerminalDisplay.h"
#include "UbuntuScreen.h"
#include "UserSession.h"
#include "Game.h"
#include <ncurses.h>
using namespace std;

int main(int argc, char** argv )
{
    shared_ptr<Board> board(new Board());
	shared_ptr<UserSession> userSession(new UserSession(board));
	unique_ptr<TerminalDisplay> terminalDisplay (new TerminalDisplay(new UbuntuScreen(), board, userSession));
	unique_ptr<Game> game(new Game(board));
	terminalDisplay->begin();
	
    return 0;
}