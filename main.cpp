#include <iostream>
#include "Board.h"
#include "TerminalDisplay.h"
#include "UbuntuScreen.h"
using namespace std;

int main(int argc, char** argv )
{
    shared_ptr<Board> board(new Board());
	unique_ptr<TerminalDisplay> terminalDisplay (new TerminalDisplay(new UbuntuScreen(), board));
	terminalDisplay->draw();
    std::cin.get(); 
    return 0;
}