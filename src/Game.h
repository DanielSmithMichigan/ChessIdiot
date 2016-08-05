#ifndef BGame_h
#define BGame_h
	#include "Square.h"
	#include "globals.h"
	#include <stdint.h>
	#include <iostream>
	#include <memory>
	#include <vector>
	#include "Board.h"
	#include "UserCommand.h"
	#include "TerminalDisplay.h"

	using namespace std;

	class Game {
		private:
			shared_ptr<Board> board;
			unique_ptr<UserCommand> userCommand;
			shared_ptr<TerminalDisplay> terminalDisplay;
		public:
			Game(shared_ptr<Board> board, UserCommand *userCommandInput, shared_ptr<TerminalDisplay> terminalDisplay);
			~Game();
			void begin();
	};
#endif