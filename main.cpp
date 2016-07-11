#include <iostream>
#include "Board.h"
#include "TerminalDisplay.h"
#include "UbuntuScreen.h"
#include "UserSession.h"
#include <ncurses.h>
using namespace std;

int main(int argc, char** argv )
{
	initscr();
	refresh();
	shared_ptr<UserSession> userSession(new UserSession());
    shared_ptr<Board> board(new Board());
	unique_ptr<TerminalDisplay> terminalDisplay (new TerminalDisplay(new UbuntuScreen(), board, userSession));
	terminalDisplay->draw();
	userSession->waitForInput();
	endwin();
    return 0;
}